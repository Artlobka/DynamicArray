#include <iostream>
#include "DynamicIntArray.h"

int main() {
    DynamicIntArray arr1(5);

    for (std::size_t i = 0; i < arr1.getSize(); i++) {
        arr1[i] = static_cast<int>(i) * 10;
    }

    std::cout << "Array contents: ";
    for (std::size_t i = 0; i < arr1.getSize(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    arr1.push_back(50);
    std::cout << "After push_back(50), new size: " << arr1.getSize() << std::endl;

    std::cout << "New array contents: ";
    for (std::size_t i = 0; i < arr1.getSize(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
