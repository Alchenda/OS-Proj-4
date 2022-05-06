//
//  ThreadCreation.hpp
//  OSProj4
//
//  Created by Danny Webb-McClain on 4/29/22.
//
#include <vector>


#ifndef ThreadCreation_hpp
#define ThreadCreation_hpp

#include <stdio.h>
#include <string>
#include "PTE.hpp"
void* CreateThread(void * arg);
void hex_string(unsigned char str[], int length);
void ProcessRegisters(vector<PTE> pages);
#endif /* ThreadCreation_hpp */
