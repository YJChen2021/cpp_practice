#include "test12_2.h"
#include "test13_T2.h"

//#define Teil1
#define Teil2

int main(){
    #ifdef Teil1
    test_Vec<double,5>();
    #endif

    #ifdef Teil2
    test_std();
    #endif
}