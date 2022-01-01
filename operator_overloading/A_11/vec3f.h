#include <iostream>
#include <array>


namespace my{
    /*Declaration*/
    class Vec3f;

    //return dot product of two 3D Vector
    float dot(const my::Vec3f& a, const my::Vec3f& b);
    
    /*Definition*/
    class Vec3f{
    public:
        //Constructor
        Vec3f(float v1 = 0, float v2 = 0, float v3 = 0);//constructor with default value
        
        /*https://www.youtube.com/watch?v=nkP-nCCEexY*/
        //operator [] for Class
        float& operator[](int index);
        
        /*http://www.cplusplus.com/forum/general/50055/*/
        //operator [] for const Class, not allowed to modify member
        const float& operator[](int index) const;
        
        //operator == for Class
        bool operator==(const Vec3f& rhs);
        
        //operator == for const Class, not allowed to modify member
        bool operator==(const Vec3f& rhs) const;

        //operator != for Class
        bool operator!=(const Vec3f& rhs);

        //operator != for const Class, not allowed to modify member
        bool operator!=(const Vec3f& rhs) const;

        //operator += for Class
        //void operator+=(const Vec3f& rhs); //is also worked, but can't be used for operator+
        //Vec3f operator+=(const Vec3f& rhs);
        Vec3f& operator+=(const Vec3f& rhs);

        //operator + for Class
        Vec3f operator+(const Vec3f& rhs);
        
        //operator + for const Class, not allowed to modify member
        Vec3f operator+(const Vec3f& rhs) const;

        /*https://www.youtube.com/watch?v=ULp4eSHL3SM*/
        //operator - for Class
        Vec3f operator-();
        
        //operator - for const Class, not allowed to modify member
        Vec3f operator-() const;

        //print vector
        void print(){std::cout<<"vector"<<vector_[0]<<vector_[1]<<vector_[2]<<std::endl;};

    private:
        std::array<float, 3> vector_;
    };
}

