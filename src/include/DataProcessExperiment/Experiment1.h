#ifndef EXPERIMENT1_H
#define EXPERIMENT1_H

#include <stdio.h>
#include "../Utils/config.h"
#include <iostream>

extern void showBytes(BytePointer start, std::size_t len);
extern void showInt(int x);
extern void showFloat(float x);
extern void showPointer(RawPointer x);

/*2.10*/
extern void inplaceSwap(IntPtr x, IntPtr y);
extern void reverseArray(int a[], int cnt);
extern void printArray(int a[], int cnt);

/*2.12*/

extern int  getEfficientData(int orgData);
extern int  get212BData(int orgData);
extern int  get212CData(int orgData);

#endif