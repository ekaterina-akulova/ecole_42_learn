//
// Created by Екатерина Акулова on 07.11.2022.
//
#include "iter.hpp"

int main(void){
    int	size;

    int arr1[] = {10, 21, 34, 45, 57, 16, 78};
    size = sizeof(arr1) / sizeof(arr1[0]);
    iter(arr1, size, print);


    std::string arr2[] = {"cat", "dog", "lion"};
    size = sizeof(arr2) / sizeof(arr2[0]);
    iter(arr2, size, print);

    float arr3[] = {4.25, 7.32, 9.12, 7.56, 11.57};
    size = sizeof(arr3) / sizeof(arr3[0]);
    iter(arr3, size, print);
/*
	std::cout << "------CLASS-----" << std::endl;
	size = 5;
	Awesome obj[size];
	iter(obj, size, printarr);
*/
    return (0);
}