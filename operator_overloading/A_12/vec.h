#include <iostream>
#include <array>


namespace my{
    /*Declaration*/
    template<typename T, int N>
    class Vec;

    //return dot product of two vectors
    template<typename T, int N>
    T dot(my::Vec<T,N> a, my::Vec<T,N> b);

    /*Definition*/
    template<typename T, int N>
    class Vec{
    public:
        //Constructor
        Vec(std::array<T,N> const& v);

        //Constructor for non-predefined vector
        Vec();
        
        //operator [] for Class
        T& operator[](int index);

        //operator [] for const Class, not allowed to modify member
        const T& operator[](int index) const;
        
        //operator == for Class
        bool operator==(const Vec& rhs);

        //operator == for const Class, not allowed to modify member
        bool operator==(const Vec& rhs) const;
        
        //operator != for Class
        bool operator!=(const Vec& rhs);
        
        //operator != for const Class, not allowed to modify member
        bool operator!=(const Vec& rhs) const;

        Vec& operator+=(const Vec& rhs);

        //operator + for Class
        Vec operator+(const Vec& rhs);

        //operator + for const Class, not allowed to modify member
        Vec operator+(const Vec& rhs)const;
        
        //operator - for Class
        Vec operator-();
        
        //operator - for const Class, not allowed to modify member
        Vec operator-() const;

    private:
        std::array<T,N> vector_;
    };
}

/*Definition*/

//Constructor
template<typename T, int N>
my::Vec<T, N>::Vec(std::array<T,N> const& v)
{
    vector_ = v;
}

//Constructor for non-predefined vector
template<typename T, int N>
my::Vec<T, N>::Vec()
{
    for(uint16_t i = 0; i < N; i++){
        vector_[i] = 0;
    }
}

//operator []
template<typename T, int N>
T& my::Vec<T,N>::operator[](int index) 
{
    return vector_[index];
}

//operator [] for const Class, not allowed to modify member
template<typename T, int N>
const T& my::Vec<T,N>::operator[](int index) const 
{
    return vector_[index];
}

//return boolean value
template<typename T, int N>
bool my::Vec<T,N>::operator==(const my::Vec<T,N>& rhs)
{
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 0;
        }
    }
    return 1;
}

//operator == for const Class, not allowed to modify member
template<typename T, int N>
bool my::Vec<T,N>::operator==(const my::Vec<T,N>& rhs) const
{
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 0;
        }
    }
    return 1;
}

//return boolean value
template<typename T, int N>
bool my::Vec<T,N>::operator!=(const my::Vec<T,N>& rhs) 
{
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 1;
        }
    }
    return 0;
}

//operator != for const Class, not allowed to modify member
template<typename T, int N>
bool my::Vec<T,N>::operator!=(const my::Vec<T,N>& rhs) const
{
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 1;
        }
    }
    return 0;
}

//operator +=
template<typename T, int N>
my::Vec<T,N>& my::Vec<T,N>::operator+=(const my::Vec<T,N>& rhs)
{
    for(uint16_t i = 0; i < N; i++){
        vector_[i] = vector_[i] + rhs[i];
    }
    return *this;
}

//operator+
template<typename T, int N>
my::Vec<T,N> my::Vec<T,N>::operator+(const my::Vec<T,N>& rhs)
{
    Vec temp = *this;
    return temp += rhs; 
}

//operator+ for const Class, not allowed to modify member
template<typename T, int N>
my::Vec<T,N> my::Vec<T,N>::operator+(const my::Vec<T,N>& rhs) const
{
    Vec temp = *this;
    return temp += rhs;  
}

//operator-
template<typename T, int N>
my::Vec<T,N> my::Vec<T,N>::operator-()
{
    Vec temp;
    for(uint16_t i = 0; i < N; i++){
        temp[i] = -vector_[i];
    }
    return temp;
}

//operator- for const Class, not allowed to modify member
template<typename T, int N>
my::Vec<T,N> my::Vec<T,N>::operator-() const
{
    Vec temp;
    for(uint16_t i = 0; i < N; i++){
        temp[i] = -vector_[i];
    }
    return temp;
}

//return dot product of two vectors
template<typename T, int N>
T my::dot(my::Vec<T,N> a, my::Vec<T,N> b)
{
    T temp = 0;
    for(uint16_t i = 0; i < N; i++){
        temp += a[i] * b[i];
    }
    return temp;
    
}