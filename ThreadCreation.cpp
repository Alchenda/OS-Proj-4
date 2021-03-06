//
//  ThreadCreation.cpp
//  OSProj4
//
//  Created by Danny Webb-McClain on 4/29/22.
//

#include "ThreadCreation.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "PTE.hpp"
using namespace std;
extern int const pageSize;
extern pthread_mutex_t lock1;

void ProcessRegisters(vector<PTE> pages){
    for (int i = 0; i < pages.size(); ++i) {
        cout << "PX Operation " << pages.at(i).GetCommand() << " " << pages.at(i).GetRegister() << " " << pages.at(i).GetVA() << endl;
    }
}

void* CreateThread(void * arg){
    string threadFileName = *(string*)arg;//type casting the void pointer
    fstream fileForThread;
    string line;
    string readInput[10][3];
    string input1, input2, input3;
    int counter = 0;
    double offset;
    int virtualMemSize;
    int bitsForPageNum;
    int pageTableSize;
    vector<PTE> pageTable;
    //open the threads respectibe file
    fileForThread.open(threadFileName);
    /*if (fileForThread.is_open()) {
        if (getline(fileForThread, line)) {
            cout << line << endl;
        }
    }*/
    while (!fileForThread.eof()) {
        if (counter == 0) {
            fileForThread >> line;
        } else {
            fileForThread >> input1; //command
            fileForThread >> input2; //register number
            fileForThread >> input3; //virtual address
            pageTable.push_back(PTE(input1, input2, input3));
        }
        counter++;
    }
    virtualMemSize = stoi(line);
    offset = log2(pageSize);
    bitsForPageNum = 32 - offset;
    pageTableSize = virtualMemSize / pageSize;
    ProcessRegisters(pageTable);
    return nullptr;
}

void hex_string(unsigned char str[], int length)
{
  int i;
    //srand(1);
  for(i=0;i<length;i++)
  {
      str[i]= rand() % 256;
  }
  str[length]=0;
}
