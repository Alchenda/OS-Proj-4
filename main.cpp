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
#include <pthread.h>
#include "ThreadCreation.hpp"

using namespace std;
ofstream outFile; //output file
pthread_mutex_t lock1;
int pageSize;
typedef struct {
    int threadNum;
} threadID;

int main(int argc, char * argv[]) {
    char *x = argv[1]; //input file
    char *y = argv[2]; //output file
    char *z = argv[3]; //seed for random number generation
    threadID args = {-5};
    int seed, mainMemSize, numThreads;
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
    //create threads and have them open their files
    //threads = new pthread_t[numThreads];
    pthread_t newThread;
    for (int i = 3; i < threadFiles.size() - 1; ++i) {
        args = {i};
        pthread_mutex_lock(&lock1);
        cout << "Process " << i - 3 << " started" << endl;
        pthread_mutex_unlock(&lock1);
        pthread_create(&newThread, nullptr, CreateThread, &threadFiles.at(i));
    }
    
    inFiles.close();
    
    
    return 0;
}
