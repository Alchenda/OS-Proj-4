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
    temp = stoi(VA);
    pageNumber = temp / 32;
    //IntToHex(temp);
}
//not working I am not sure why
void PTE::IntToHex(int convert){
        // char array to store hexadecimal number
        char hexaDeciNum[100];
     
        // counter for hexadecimal number array
        int i = 0;
        while (convert != 0) {
        // temporary variable to store remainder
        int temp = 0;
     
        // storing remainder in temp variable.
        temp = convert % 16;
     
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
     
        convert = convert / 16;
    }
     
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
            VirtAdd += hexaDeciNum[j];
}
void PTE::PrintVA(){
    cout << "current first page VA " << VirtAdd << endl;
}
void PTE::PrintReg(){
    cout << regNum << endl;
}
