#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

/*
Smart Pointers
preserving state
PA5
*/

template <typename T>
class SmartPtr {
public:
    SmartPtr() = default;

    SmartPtr(T* aPtr) : ptr(aPtr) {}

    SmartPtr(const SmartPtr& aCopy) {
        return *this = aCopy;
    }

    SmartPtr& operator=(const SmartPtr& aCopy) {
        T temp = *aCopy.ptr;
        delete ptr;
        ptr = new T(temp);
        return *this;
    }
    ~SmartPtr() {
        delete ptr;
    }
    operator T() const {
        return *ptr;
    }

    T& operator*() {
        return *ptr;
    }
    
protected:
    T* ptr;
};

template <typename T>
void saveVector(std::vector<T>& aVec) {

}

template <typename T>
void readVector(std::vector<T>& aVec) {
}

template <typename T>
void printVector(std::vector<T>& aVec) {
    for (auto& e : aVec) {
        std::cout << e << " ";
    }
}

int main() {
    std::vector<int> theVec = { 1, 2, 3, 4 };
    saveVector(theVec);
    std::vector<int> theReadVec;
    readVector(theReadVec);
    printVector(theReadVec);
    return 0;
}



/*
template <typename T>
void saveVector(std::vector<T>& aVec) {
    std::ofstream file;
    file.open("vector.txt");
    for (int i = 0; i < aVec.size(); ++i) {
        file << aVec[i] << std::endl;
    }
    file.close();
}

template <typename T>
void readVector(std::vector<T>& aVec) {
    std::ifstream file;
    std::stringstream sstream;
    file.open("vector.txt");
    std::string line;
    T temp;
    while (getline(file, line)) {
        sstream << line;
        sstream >> temp;
        aVec.push_back(temp);
        sstream.clear();
    }
    file.close();
}

template <typename T>
void printVector(std::vector<T>& aVec) {
    for (auto& e : aVec) {
        std::cout << e << " ";
    }
}
*/