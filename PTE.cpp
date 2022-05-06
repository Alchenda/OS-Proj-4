//
//  PTE.cpp
//  OSProj4
//
//  Created by Danny Webb-McClain on 5/3/22.
//

#include "PTE.hpp"
#include <string>
#include <iostream>
#include <sstream>
//create a single page table entry, each of these entries will be stored in a vector
using namespace std;
PTE::PTE(string command, string registerNum, string VA){
    int temp;
    RW = command;
    regNum = registerNum;
    std::stringstream ss;
    VirtAdd = VA;
    temp = stoi(VA);
    pageNumber = temp / 32;
    referenceBit = 0;
    validBit = 0;
    
}
string PTE::GetCommand(){
    return RW;
}
string PTE::GetRegister(){
    return regNum;
}
string PTE::GetVA(){
    return VirtAdd;
}
void PTE::PrintReg(){
    cout << regNum << endl;
}
