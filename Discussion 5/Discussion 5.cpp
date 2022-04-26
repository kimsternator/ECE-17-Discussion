#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

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

// Function Overloading + Templates
// Two of Same Type
template <typename T>
bool equals(const T& aLeft, const T& aRight);
// Type against int
template <typename T>
bool equals(const T& aLeft, const int& aRight);
// Type against float
template <typename T>
bool equals(const T& aLeft, const float& aRight);
// Type 1 against Type 2
template <typename T1, typename T2>
bool equals(const T1& aLeft, const T2& aRight);

int main() {
    // How to Declare/Initialize Template Object
    Node<int> theNode {1, nullptr};
    std::vector<int> theVec;
    std::vector<Node<int>> theVec2;

    // STL Standard TEMPLATE Library
    // std::vecetor<int> theVec;
    
    // std::list<int> theList;
    
    // stack - LIFO - Last In First Out
    // push, peek, pop
    /* Stack    Action
    1           push(1);
    2 1         push(2);
    2           peek();
    1           pop();
    */

    // queue - FIFO - First In First Out - single ended queue
    // push, pop
    /* Queue    Action
    1           push(1);
    1 2         push(2);
    2           pop();
    */

    // deque 
    // push_front, push_back, pop_front, pop_back
    /* Deque    Action
    1           push_back(1);
    1 2         push_back(2);
    3 1 2       push_front(3);
    3 1         pop_back();
    */

    // Map
    // Key-Value Pairs 
    // <int, string>
    // { 1, "1"}
    // {3, "3"}
    
    // Ordered Map - keeps track of order of inserted pairs
    // Can still iterate theMap.begin() -> theMap.end();

    // One use of maps - Map of <ENUM, function>
    // add, subtract, multiply, divide
    // enum corresponding to above ENUM::add 

    /* If we have map of functions theMapFunctions = {{ENUM::add, addFunction}, ...}
    switch(enum) {
        case ENUM::add: {
            add();
            break;
        }
    }

    or we can do this

    theMapFunctions[ENUM::add]();
    */

    // We need these:
    // 1) Collection 2) Iterators
    
    // sort - sorts the collection depending on what order you pass (default increasing order)

    // reverse - flips the direction of the collection
    // 1, 2, 3 -> 3, 2, 1

    // find - finds a certain element and returns it's position (index) or std::nopos

    // accumulate - running sum over collection
    // 1 2 3 -> 6

    /*try { run code
        std::vector<int> testVector;
        throw std::exception("I threw an exception");
    } catch () { catch exception in try block
        std::cout << "Caught an Exception" << std::endl;
    }*/

    // set collection - List of No Duplicate Values
    /* Set    Action
    1           add(1);
    1 2         add(2);
    1 2 3       add(3);
    1 2 3       add(1);
    */
    
    // One example set use: make own multimap
    // Regular map - K-V all keys must be unique
    // Multimap multiple of the same keys

    // priority queue 
    // collection -> as you add elements, they get sorted
    /* Priority Action
    5           add(5);
    1 5         add(1);
    1 2 5       add(2);
    */

    // Lambda Function
    std::vector<Node<int>> theVec;
    std::sort(theVec.begin(), theVec.end(), [](const Node<int>& aLeft, const Node<int>& aRight) {
        return !(aLeft.value < aRight.value);
    });
}
