//
//  PTE.hpp
//  OSProj4
//
//  Created by Danny Webb-McClain on 5/3/22.
//

#ifndef PTE_hpp
#define PTE_hpp

#include <stdio.h>
#include <string>
using namespace std;
class PTE{
public:
    PTE();
    PTE(string command, string registerNum, string VA);
    int GetValidBit();
    int GetReferenceBit();
    int GetPageNumber();
    string GetCommand();
    string GetRegister();
    string GetVA();
    void PrintReg();
    void IntToHex(int convert);
private:
    string RW;
    string regNum;
    string VirtAdd;
    int pageNumber;
    int referenceBit;
    int validBit;
    int FrameNumber;
    
};
#endif /* PTE_hpp */
