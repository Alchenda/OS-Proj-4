//
//  ThreadCreation.cpp
//  OSProj4
//
//  Created by Danny Webb-McClain on 4/29/22.
//

#include "ThreadCreation.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
extern int const pageSize;
extern pthread_mutex_t lock1;
void* CreateThread(void * arg){
    int* pageTable; // needs to be dynamically allocated since it changes based on size given
    string threadFileName = *(string*)arg;//type casting the void pointer
    fstream fileForThread;
    string line;
    double offset;
    int virtualMemSize;
    int bitsForPageNum;
    int pageTableSize;
    pthread_mutex_lock(&lock1);
    cout << "This is the thread that is going to be read " << threadFileName << endl;
    pthread_mutex_unlock(&lock1);
    fileForThread.open(threadFileName);
    if (fileForThread.is_open()) {
        if (getline(fileForThread, line)) {
            cout << line << endl;
        }
    }
    virtualMemSize = stoi(line);
    offset = log2(pageSize);
    bitsForPageNum = 32 - offset;
    pageTableSize = pow(2, bitsForPageNum);
    return nullptr;
}
