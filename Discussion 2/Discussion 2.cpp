#include <iostream>
#include <vector>
#include <algorithm>

#include "Card.hpp"

/*
classes OCF x
STL x
enums
*/

// Function to print a vector
void printVec(const std::vector<int> &a) {
    for (auto i : a) {
        std::cout << i << "\n";
    }
}

int main()
{
    std::vector<int> a = { 3, 1, 4, 2 };
    printVec(a);
    std::sort(a.begin(), a.end());
    /*
    Useful STL functions
    std::remove
    std::erase
    std::sort
    std::find
    std::find_if

    std::shuffle
    */
    std::cout << "\n";
    printVec(a);
}