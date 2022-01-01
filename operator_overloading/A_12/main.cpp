#include <iostream>
#include "cassert"
//#define Aufgabe1_2_2
#define Aufgabe1_2_3

#ifdef Aufgabe1_2_2
#include "test12_2.h"
#endif

#ifdef Aufgabe1_2_3
#include "test12_3.h"
#endif

int main(){
    
    #ifdef Aufgabe1_2_2
    test_Vec3f();
    #endif
    
    #ifdef Aufgabe1_2_3
    test_Vec<float,5>();
    #endif

}