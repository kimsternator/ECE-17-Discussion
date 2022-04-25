#include <iostream>
#include <vector>
#include <algorithm>

/*
Templates
    Single Template
    Multiple Template
    Using Template Object

STL
    Template
    vector, list, stack, queue, map (ordered, unordered)
    sort, reverse, find, accumulate

Exceptions
    exceptions
    try-catch

set if we have time
priority queue if we have time
lambda if we have time
*/

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T1, typename T2>
struct DoubleNode {
    T1 value1;
    T2 value2;
    DoubleNode* next;
};

int main() {
    std::cout << "Hello World!\n";
}
