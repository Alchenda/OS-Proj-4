//
//  main.cpp
//  OSProj4
//
//  Created by Danny Webb-McClain on 4/29/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <list>
#include <pthread.h>
#include "ThreadCreation.hpp"

using namespace std;
ofstream outFile; //output file
pthread_mutex_t lock1;
int pageSize;
typedef struct {
    int threadNum;
} threadID;
list<int> readyFrameList;
int main(int argc, char * argv[]) {
    //Dynamically allocation
    unsigned char * physicalMemory;
    
    //Variable initialization
    char *x = argv[1]; //input file
    char *y = argv[2]; //output file
    char *z = argv[3]; //seed for random number generation
    threadID args = {-5};
    int seed, mainMemSize, numThreads, freeFrameSize;
    string tempLoad;
    vector<string> threadFiles;
    fstream inFiles;
    pthread_t *threads;
    pthread_mutex_init(&lock1, NULL);
    
    //begin program
    inFiles.open(argv[1]);
    outFile.open(argv[2]);
    seed = stoi(argv[3]);
    if (inFiles.is_open()) {
        while (inFiles) {
            inFiles >> tempLoad;
            threadFiles.push_back(tempLoad);
            cout << tempLoad << endl;
        }
    }
    inFiles.close();
    mainMemSize = stoi(threadFiles.at(0));
    pageSize = stoi(threadFiles.at(1));
    numThreads = stoi(threadFiles.at(2));
    //Establish size of main memory array
    physicalMemory = new unsigned char [mainMemSize];
    //now that the size of the physical memory array has been established, this needs to be filled with random values
    srand(seed);
    hex_string(physicalMemory, mainMemSize);
    //std::cout << std::hex << (int)physicalMemory[i] << " "; convert to hex
    cout << "Testing physical memory fill" << endl;
    
    //Establish free frame list and list size
    freeFrameSize = mainMemSize / pageSize; //number of frames that are in physical memory
    for (int i = 0; i < freeFrameSize; ++i) {
        readyFrameList.push_back(i); //every frame starts off ready so populate with every frame
    }
    //create threads and have them open their files
    pthread_t newThread;
    for (int i = 3; i < threadFiles.size() - 1; ++i) {
        args = {i};
        pthread_mutex_lock(&lock1);
        cout << "Process " << i - 3 << " started" << endl;
        pthread_mutex_unlock(&lock1);
        pthread_create(&newThread, nullptr, CreateThread, &threadFiles.at(i));
    }
    inFiles.close();


    pthread_exit(nullptr);
    
    return 0;
}
