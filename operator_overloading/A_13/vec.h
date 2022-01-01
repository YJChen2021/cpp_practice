#include <algorithm>
#include <array>
#include <numeric>
#include <iostream>


namespace my{
    /*Declaration*/
    template<typename T, int N>
    class Vec;

    //return dot product of two vectors
    template<typename T, int N>
    T dot(const my::Vec<T,N>& a, const my::Vec<T,N>& b);

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
        
        //return euclidean distance of vector
        T length();

        //return euclidean distance of vector - for const Class, not allowed to modify member
        T length() const;
        
        friend T my::dot(const my::Vec<T,N>& a, const my::Vec<T,N>& b);
    
    private:
        std::array<T,N> vector_;
    };

    /*can also be implemented by using "friend"*/
    template<typename T, int N>
    void helper(const my::Vec<T,N>& vector);

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
    /*
    for(uint16_t i = 0; i < N; i++){
        vector_[i] = 0;
    }
    */
    std::fill(vector_.begin(), vector_.end(), (T)0);
}

//operator []
template<typename T, int N>
T& my::Vec<T,N>::operator[](int index) 
{
    return vector_[index];
}

// operator [] for const Class, not allowed to modify member
template<typename T, int N>
const T& my::Vec<T,N>::operator[](int index) const 
{
    return vector_[index];
}

//return boolean value
template<typename T, int N>
bool my::Vec<T,N>::operator==(const my::Vec<T,N>& rhs)
{
    /*
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 0;
        }
    }
    return 1;
    */
   return std::equal(vector_.begin(), vector_.end(), rhs.vector_.begin(), rhs.vector_.end());
}

//operator == for const Class, not allowed to modify membe
template<typename T, int N>
bool my::Vec<T,N>::operator==(const my::Vec<T,N>& rhs) const
{
    /*
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 0;
        }
    }
    */
    return std::equal(vector_.begin(), vector_.end(), rhs.vector_.begin(), rhs.vector_.end());
}

//return boolean value
template<typename T, int N>
bool my::Vec<T,N>::operator!=(const my::Vec<T,N>& rhs) 
{
    /*
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 1;
        }
    }
    */
    return !(std::equal(vector_.begin(), vector_.end(), rhs.vector_.begin(), rhs.vector_.end()));
}

//operator != for const Class, not allowed to modify member
template<typename T, int N>
bool my::Vec<T,N>::operator!=(const my::Vec<T,N>& rhs) const
{
    /*
    for(uint16_t i = 0; i < N; i++){
        if(vector_[i] != rhs[i]){
            return 1;
        }
    }
    */
    return !(std::equal(vector_.begin(), vector_.end(), rhs.vector_.begin(), rhs.vector_.end()));
}

//operator +=
template<typename T, int N>
my::Vec<T,N>& my::Vec<T,N>::operator+=(const my::Vec<T,N>& rhs)
{
    /*
    for(uint16_t i = 0; i < N; i++){
        vector_[i] = vector_[i] + rhs[i];
    }
    */
    std::transform (vector_.begin(), vector_.end(), rhs.vector_.begin(), vector_.begin(), std::plus<T>());
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
    /*
    for(uint16_t i = 0; i < N; i++){
        temp[i] = -vector_[i];
    }
    */
    std::transform(vector_.begin(), vector_.end(), temp.vector_.begin(), [](T v){return -v;});
    return temp;
}

//operator- for const Class, not allowed to modify member
template<typename T, int N>
my::Vec<T,N> my::Vec<T,N>::operator-() const
{
    Vec temp;
    /*
    for(uint16_t i = 0; i < N; i++){
        temp[i] = -vector_[i];
    }
    */
    std::transform(vector_.begin(), vector_.end(), temp.vector_.begin(), [](T v){return -v;});
    return temp;
}

//return euclidean distance of vector
template<typename T, int N>
T my::Vec<T,N>::length()
{
    return sqrt(my::dot<T,N>(*this, *this));
}

//return euclidean distance of vector, for const Class, not allowed to modify member
template<typename T, int N>
T my::Vec<T,N>::length() const
{
    return sqrt(my::dot<T,N>(*this, *this));
}

//print elements of vector and eucliden distance(length) in terminal
template<typename T, int N>
void my::helper(const my::Vec<T,N>& vector)
{
    std::cout<<"\n";
    std::cout<<"Elements:";
    for(uint16_t i = 0; i < N; i++){
        //std::cout << vector_[i] << ",";
        (i != N - 1)?std::cout << vector[i] << ",":std::cout << vector[i] <<'.';
    }
    std::cout<< "length:" << vector.length() <<std::endl;
    std::cout<<"\n";
}

//return dot product of two vectors
template<typename T, int N>
T my::dot(const my::Vec<T,N>& a, const my::Vec<T,N>& b)
{
    /*
    T temp = 0;
    
    for(uint16_t i = 0; i < N; i++){
        temp += a[i] * b[i];
    }
    
    return temp;
    */
    return static_cast<T>(std::inner_product(a.vector_.begin(), a.vector_.end(), b.vector_.begin(), 0));
}