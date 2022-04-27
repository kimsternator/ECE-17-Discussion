#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedList.hpp"
// aLinkedList = {1, 2, 3, 2}
using namespace std;

struct Object {
    int a;
};

void printVec(vector<Object> aVec) {
    for (auto& obj : aVec) {
        std::cout << obj.a << " ";
    }
    std::cout << std::endl;
}

int main()
{
    //ECE17::Node* theNode = nullptr; // Initialized and Declared
    //ECE17::Node* uninitNode; // Only Declared

    //int a = 0;
    //Node* theFindNode = aLinkedList.find(2); // return the second item
    //Node* theSecondFindNode = aLinkedList.find(2, theFindNode->next); // Start at the third Item -> find another Node with value 2

    int comparatorValue = 4;

    vector<Object> theVec = { Object{3}, Object{1}, Object{2}, Object{4} };
    printVec(theVec);

    /*std::sort(theVec.begin(), theVec.end(), [comparatorValue](const Object& aLeft, const Object& aRight) {
        return aLeft.a < ;
    });*/

    auto result = std::find_if(theVec.begin(), theVec.end(), [=](const Object& anObj) {
        return anObj.a == comparatorValue;
    });
    std::cout << "Result: " << result->a << "\n";
    
    printVec(theVec);
}
