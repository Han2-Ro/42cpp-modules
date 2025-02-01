#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int subj()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

void my_test() {
    {
        Array<int> arr;
        std::cout << "arr: " << arr << std::endl;
        std::cout << "size: " << arr.size() << std::endl;
        try {
            std::cout << arr[0] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        Array<int> arr(5);
        std::cout << "arr: " << arr << std::endl;
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;
        std::cout << "arr: " << arr << std::endl;
        try {
            std::cout << arr[5] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "size: " << arr.size() << std::endl;
    }
    std::cout << std::endl;
    {
        Array<std::string> arr(3);
        std::cout << "arr: " << arr << std::endl;
        arr[0] = "hello";
        arr[1] = "world";
        arr[2] = "!";
        std::cout << "arr: " << arr << std::endl;
        try {
            std::cout << arr[-1] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "size: " << arr.size() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Test copy constructor" << std::endl;
        Array<int> arr1(5);
        arr1[0] = 42;
        arr1[1] = 0;
        arr1[2] = 420;
        arr1[3] = 120;
        arr1[4] = -9999;
        Array<int> arr2(arr1);
        std::cout << "arr1: " << arr1 << " size: " << arr1.size() << std::endl;
        std::cout << "arr2: " << arr2 << " size: " << arr2.size() << std::endl;
        arr1[0] = 1;
        arr1[1] = 2;
        arr2[2] = 3;
        arr2[3] = 4;
        std::cout << "arr1: " << arr1 << " size: " << arr1.size() << std::endl;
        std::cout << "arr2: " << arr2 << " size: " << arr2.size() << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Test copy assignment operator" << std::endl;
        Array<std::string> arr1(3);
        arr1[0] = "this";
        arr1[1] = "is";
        arr1[2] = "arr1";
        std::cout << "arr1: " << arr1 << " size: " << arr1.size() << std::endl;
        Array<std::string> arr2(2);
        arr2[0] = "this";
        arr2[1] = "arr2";
        std::cout << "arr2: " << arr2 << " size: " << arr2.size() << std::endl;
        arr2 = arr1;
        std::cout << "arr2: " << arr2 << " size: " << arr2.size() << std::endl;
        arr1[0] = "hello";
        arr1[1] = "world";
        arr2[2] = "arr2";
        std::cout << "arr1: " << arr1 << " size: " << arr1.size() << std::endl;
        std::cout << "arr2: " << arr2 << " size: " << arr2.size() << std::endl;
    }
}


int main() {
    my_test();
    std::cout << "-----------------------" << std::endl;
    subj();
    return 0;
}