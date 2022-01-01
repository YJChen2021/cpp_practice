#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include "vec.h"

using vec3f = my::Vec<float, 3>;

void test_std(){
    std::vector<vec3f> vec3f10;

    //Generate random value    
    /*Reference: https://stackoverflow.com/questions/686353/random-float-number-generation*/
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(0, 100);

    for(uint8_t i = 0; i < 10; i++){
        vec3f temp;
        //cout<<dist(e2)<<endl;
        for(uint8_t i = 0; i < 3; i++){
            temp[i] = (float)dist(e2);
        }
        vec3f10.push_back(temp);
    }

    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"random vectors:"<<std::endl;
    std::for_each(vec3f10.begin(), vec3f10.end(), [](vec3f single_vector){my::helper<float, 3>(single_vector);});

    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"add 1 to all elements of vectors:"<<std::endl;
    std::transform(vec3f10.begin(), vec3f10.end(), vec3f10.begin(),[](vec3f single_vector){vec3f temp({1.0,1.0,1.0});return (single_vector+=temp);});
    std::for_each(vec3f10.begin(), vec3f10.end(), [](vec3f single_vector){my::helper<float, 3>(single_vector);});

    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"divides vector into two groups(length < 90 and length > 90)"<<std::endl;
    std::stable_partition(vec3f10.begin(),vec3f10.end(), [](vec3f single_vector){return (single_vector.length() < 90);});
    std::for_each(vec3f10.begin(), vec3f10.end(), [](vec3f single_vector){my::helper<float, 3>(single_vector);});

    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"sort(descending order)"<<std::endl;
    //v2 = array[i], v1 = array[i + 1], v if v1 > v2, then swap, 
    //bigger one moves forward -> descending order
    std::sort(vec3f10.begin(),vec3f10.end(),[](vec3f v1, vec3f v2){return v1.length() > v2.length();});
    std::for_each(vec3f10.begin(), vec3f10.end(), [](vec3f single_vector){my::helper<float, 3>(single_vector);});

    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"Median"<<std::endl;    
    //Median: index = 5 or index = 4??
    vec3f Median = vec3f10[5];
    my::helper(Median);
    //vec3f Median = vec3f10[4];

    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"make a new container for all vectors with lenth less than 80"<<std::endl;
    std::vector<vec3f> vec3f10_smaller_than_80;
    std::copy_if(vec3f10.begin(), vec3f10.end(), std::back_inserter(vec3f10_smaller_than_80), [](vec3f single_vector){return(single_vector.length() < 80);});
    std::for_each(vec3f10_smaller_than_80.begin(), vec3f10_smaller_than_80.end(), [](vec3f single_vector){my::helper<float, 3>(single_vector);});
    
    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<"remove the vectors with length between 90 and 120 in container"<<std::endl;
    /*Reference: SU-Folien*/
    /*std :: remove_if () does not delete, but sorts the elements to be removed behind the elements to be remained.
    Container :: erase receives iterator on the first element to be deleted.*/
    auto to_be_erased = remove_if(vec3f10.begin(), vec3f10.end(), [](vec3f single_vector){return (single_vector.length() <= 120 && single_vector.length() >= 90);});
    vec3f10.erase(to_be_erased, vec3f10.end());
    std::for_each(vec3f10.begin(), vec3f10.end(), [](vec3f single_vector){my::helper<float, 3>(single_vector);});
}