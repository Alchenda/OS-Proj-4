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
void PTE::FreeFrame(){
 // print frame number to file if frame is available
 /*
  * if (pageNumber.isFull == true) {
  *  cout << "Using free frame" << endl;
  * }
  *
  *
  */
}

void PTE::Evict(){
    // print thread and page if page is being evicted
    /*
     * if (pageNumber.isEvicted == true){
     * // cout << "evicting process" << endl;
     * }
     *
     */
}

void PTE::Translation() {
    /*
     *
     * // determine if translation is valid
     *
     *
     * // handle translations from page to frame
     *
     *
     * // translating virtual address to physical address
     *
     */
}
