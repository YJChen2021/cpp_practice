#pragma once
#include <iostream>
#include <cassert>
#include <typeinfo>
//#include <algorithm>
using namespace std;

#include "vec.h"
using namespace my;

template<typename T, int N>
void test_Vec();


template<typename T, int N>
void test_Vec() {

//#ifndef NDEBUG

    cout << "======================" << endl;
    cout << "     Testing Vec      " << endl;
    cout << "======================" << endl;

    {
        // do not tolerate any memory overhead
        cout << "  sizeof(Vec) == "<< sizeof(Vec<T, N>) <<" bytes: ";
        assert( sizeof(Vec<T,N>) == N * sizeof(T) );
        cout << "passed." << endl;
    }

    {
        cout << "  constructor & index operator: ";
        Vec<T, N> a;
        
        for(uint16_t i = 0; i < N; i++){
            assert( a[i] == 0 );
        }
        
        Vec<T, N> b;
        for(uint16_t i = 0; i < N; i++){
            b[i] = N;
            assert( b[i] == N );
        }
        cout << "passed." << endl;
    }

    {
        cout << "  read-only access to const object: ";
        Vec<T,N> temp;
        for(uint16_t i = 0; i < N; i++){
            temp[i] = (T)i + 1;
        }
        const Vec<T,N> a = temp;
        // the next line will throw a compiler error if there is no proper "operator[] const"
        assert( a[1] == 2 );
        cout << "passed." << endl;
    }

    {
        cout << "  write access to a non-const object: ";
        Vec<T,N> a;
        for(uint16_t i = 0; i < N; i++){
            a[i] = (T)i + 1;
        }
        a[1] = 4;
        for(uint16_t i = 0; i < N; i++){
            if(i != 1){
                assert( a[i] == i + 1);
            }
            else{
                assert( a[1] == 4);
            }
        }
        
        cout << "passed." << endl;
    }
 
    {
        cout << "  comparison: ";        
        Vec<T,N> a, b, c, d;
        for(uint16_t i = 0; i < N; i++){
            a[i] = (T)i + 1;
            b[i] = (T)i + 1;
            c[i] = (T)i + 1;
            d[i] = (T)i + 4;
        }
        c[N - 1] += 6; 
        assert( a == b );
        assert( a == a );
        assert( a != c );
        assert( b != d );
        assert( !(a != b) );
        cout << "passed." << endl;
    }
   
    {
        // should work out of the box when using std container (!)
        cout << "  assignment: "; 
        Vec<T,N> a;
        for(uint16_t i = 0; i < N; i++){
            a[i] = (T)i + 1;
        }
        cout << a[0] << " "; // to make sure these values are not optimized away! 
        Vec<T,N> temp;
        for(uint16_t i = 0; i < N; i++){
            temp[i] = (T)i + 4;
        }
        a = temp;
        for(uint16_t i = 0; i < N; i++){
            assert( a[i] == i + 4 );
        }
        
        cout << "passed." << endl;
    }

    {
        cout << "  addition: ";
        Vec<T,N> a, b, temp;
        for(uint16_t i = 0; i < N; i++){
            a[i] = (T)i + 1;
            b[i] = (T)i + 4;
        }
        a += b;
        for(uint16_t i = 0; i < N; i++){
            temp[i] = (T)2 * i + 5;
        }
        assert( a == temp );
        for(uint16_t i = 0; i < N; i++){
            temp[i] = 1;
        }
        auto c = a + temp;
        for(uint16_t i = 0; i < N; i++){
            temp[i] = a[i] + 1;
        }
        assert( c == temp );
        Vec<T,N> one, four;
        for(uint16_t i = 0; i < N; i++){
            one[i] = 1;
            four[i] = 4;
        }        
        one += one+one+one;
        assert( one == four);
        
        Vec<T,N> x, y, z;
        for(uint16_t i = 0; i < N; i++){
            x[i] = 0;
            y[i] = 1;
            z[i] = 2;
        }     
        x += y += z;
        for(uint16_t i = 0; i < N; i++){
            temp[i] = 3;
        }
        assert( y == temp );
        assert( x == y );
        cout << "passed." << endl;
    }
    
    {
        cout << "  unary minus: ";
        Vec<T,N> a;
        for(uint16_t i = 0; i < N; i++){
            a[i] = (T)i + 1;
        }
        Vec<T,N> temp;
        for(uint16_t i = 0; i < N; i++){
            temp[i] = -((T)i + 1);
        }
        assert( -a == temp );
        cout << "passed." << endl;
    }
  
    {
        cout << "  dot product: ";
        Vec<T,N> a;
        T temp = 0;
        for(uint16_t i = 0; i < N; i++){
            a[i] = (T)i + 1;
            temp += (((T)i + 1) * ((T)i + 1));
        }
        assert(( dot(a,a) == temp ));
        cout << "passed." << endl;
    }

    {
        // these tests will not compile if you forgot to declare 
        // some methods const
        cout << "  constness: ";
        Vec<T,N> temp;
        for(uint16_t i = 0; i < N; i++){
            temp[i] = (T)i + 1;
        }
        const Vec<T,N> a = temp;
        assert( a[1] == 2 );
        assert( a == a );
        assert( ! (a != a) );
        
        for(uint16_t i = 0; i < N; i++){
            temp[i] = a[i] + a[i];
        }
        assert( a+a == temp );
        for(uint16_t i = 0; i < N; i++){
            temp[i] = -a[i];
        }
        assert( -a == temp );
        T temp2 = 0;
        for(uint16_t i = 0; i < N; i++){
            temp2 += (((T)i + 1) * ((T)i + 1));
        }
        assert(( dot(a,a) == temp2 ));
        cout << "passed." << endl;
    }

    cout << "all Vec tests passed." << endl << endl;   

}
