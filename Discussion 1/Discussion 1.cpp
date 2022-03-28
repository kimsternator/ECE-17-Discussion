#include <iostream>
#include <string>

class Object2 {
public:
    void function1() {
        std::cout << "Hello World!\n";
    }

    int num1;
    int num2;
    std::string name;
};

int main()
{
    //Object2* objPtr = new Object2(); // nullptr -> 0x000234234Sdf
    //objPtr->function1();
    Object2 objObject{0, 1, "string"};
    std::cout << "1\n";
    int a = 1;
}