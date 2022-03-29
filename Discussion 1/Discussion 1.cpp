#include <iostream>
#include <string>

// Introducing classes (not present in C)
class ClassObject {
public:
    // Functions just like inside structs
    // This function changes the variables attached to the current instance of a class
    void changeNum(int newNum1) {
        num1 = newNum1;
    }
    void function1() const { // can add const keyword because class does not change
        std::cout << "Hello World!\n";
    }

    int num1;
    int num2;
    std::string name;
};

int main() {
    // Declaring and initializing a pointer to instance of object
    ClassObject const* objPtr = new ClassObject(); // nullptr -> 0x000234234Sdf
    objPtr->function1();
    // Declaring and initializing a reference to instance of object
    ClassObject objObject{ 0, 1, "string" };
    // Must delete our pointer
    // Falling out of scope deletes the variable but our variable is a pointer so we need to delete the object instance
    delete objPtr;
}
