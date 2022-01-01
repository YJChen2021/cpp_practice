#include "vec3f.h"

//Constructor
my::Vec3f::Vec3f(float v1, float v2, float v3)
{
    vector_ = {v1, v2, v3};
}

//operator []
//if return by value: value[index](value) = z(value2) - error
//if return by reference: vector[index](reference) = value - correct
float& my::Vec3f::operator[](int index) 
{
    return vector_[index];
}

//for const Class, not allowed to modify member
const float& my::Vec3f::operator[](int index) const 
{
    return vector_[index];
}

//return boolean value
bool my::Vec3f::operator==(const my::Vec3f& rhs)
{
    return ((vector_[0] == rhs[0]) && (vector_[1] == rhs[1]) && (vector_[2] == rhs[2]));
}

//operator ==for const Class, not allowed to modify member
bool my::Vec3f::operator==(const my::Vec3f& rhs) const
{
    return ((vector_[0] == rhs[0]) && (vector_[1] == rhs[1]) && (vector_[2] == rhs[2]));
}

//return boolean value
bool my::Vec3f::operator!=(const my::Vec3f& rhs) 
{
    return !((vector_[0] == rhs[0]) && (vector_[1] == rhs[1]) && (vector_[2] == rhs[2]));
}

//operator != for const Class, not allowed to modify member
bool my::Vec3f::operator!=(const my::Vec3f& rhs) const
{
    return !((vector_[0] == rhs[0]) && (vector_[1] == rhs[1]) && (vector_[2] == rhs[2]));
}

/*
void my::Vec3f::operator+=(const my::Vec3f& rhs)
{
    vector_[0] = vector_[0] + rhs[0];
    vector_[1] = vector_[1] + rhs[1];
    vector_[2] = vector_[2] + rhs[2];
}
*/
/*
my::Vec3f my::Vec3f::operator+=(const my::Vec3f& rhs)
{
    vector_[0] = vector_[0] + rhs[0];
    vector_[1] = vector_[1] + rhs[1];
    vector_[2] = vector_[2] + rhs[2];
    return *this;
}
*/

//operator +=
my::Vec3f& my::Vec3f::operator+=(const my::Vec3f& rhs)
{
    vector_[0] = vector_[0] + rhs[0];
    vector_[1] = vector_[1] + rhs[1];
    vector_[2] = vector_[2] + rhs[2];
    return *this;
}

//operator+
my::Vec3f my::Vec3f::operator+(const my::Vec3f& rhs)
{   
    Vec3f temp = *this;
    return temp += rhs;
}

//operator+ for const Class, not allowed to modify member
my::Vec3f my::Vec3f::operator+(const my::Vec3f& rhs) const
{
    Vec3f temp = *this;
    return temp += rhs;
}

//operator-
my::Vec3f my::Vec3f::operator-()
{
    return Vec3f(-vector_[0], -vector_[1], -vector_[2]);
}

//operator- for const Class, not allowed to modify member
my::Vec3f my::Vec3f::operator-() const
{
    return Vec3f(-vector_[0], -vector_[1], -vector_[2]);
}

//return dot product of two 3D vector
float my::dot(const my::Vec3f& a, const my::Vec3f& b)
{
    return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}