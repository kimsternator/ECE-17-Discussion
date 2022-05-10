#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using std::string; using std::vector;
// Data
class Coordinates {
    int x, y;
};
// Models
class Volcano {};
// Relationships (has-a, is-a)
class Account;

class UserAccount {
    int totalMoney;
    vector<Account> monetaryAccounts;
};
class Account {};

class CheckingAccount : public Account {};
class SavingAccount : public Account {};
class Bank {
    vector<UserAccount> users;
    int totalMoney;
    UserAccount user;
};
// Functor
class Button {
public:
    void operator()() {
        state = !state;
    }
private:
    bool state;
};
// Interface
class INodeVisitor {
public:
    virtual void visit() {
        std::cout << "Interface" << std::endl;
    }
};

class NodeVisitor : public INodeVisitor {
public:
    NodeVisitor() = default;
    void visit() override {
        std::cout << "Derived" << std::endl;

    }
};

/*
a(...) function argument (aName -> argument Name)
the(...) local variable (the -> local variable)

I(...) Interfaces -> Pure Virtual Class 
*/

// Process
class JSONObject {};
class HTTP {
public:
    enum class HTTPCODES { STATUS_200 = 200, STATUS_401 = 401, STATUS_404 = 404 };
    // GET POST
    class HTTPRequest {
        string type;
        JSONObject body;
        string host;
        string target;
    };

    class HTTPResponse {
        HTTPCODES code;
        JSONObject body;
    };

    void initialize();
    void CreateRequest();
    void SendRequest();
    void ReadReponse();

private:
    void ValidateRequest();
    void ReceiveReponse();
    void ValidateReponse();

    HTTPRequest request;
    HTTPResponse response;
};
// Utilities
class Printer {
public:
    static void print(string aString, bool newLine = false) {
        std::cout << aString << (newLine ? "\n" : "");
    }
};

/*
The tall grass is in the house.
1 tall grass is in 1 house.

"The" -> 1

The tall grass is in the house.


"is" -> 123
The tall grass is in the house.
The tall grass 123 in the house.
*/


/* The tall grass is in the house.

*/

void printMap(std::unordered_map<string, int> aMap) {
    for (auto pair : aMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

int main() {
    string paragraph = "The tall grass is in the house.";
    std::unordered_map<string, int> theWordFrequencies;
    std::stringstream theStream;
    theStream << paragraph;
    string theWord;
    while (theStream) {
        theStream >> theWord;
        std::transform(theWord.begin(), theWord.end(), theWord.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        theWord.erase(std::remove_if(theWord.begin(), theWord.end(), ispunct));

        if (std::find_if(theWordFrequencies.begin(), theWordFrequencies.end(), [&](const std::pair<string, int>& theCompare) {
            return theCompare.first == theWord;
        }) == theWordFrequencies.end()) {
            theWordFrequencies[theWord] = 1;
        } else {
            theWordFrequencies[theWord]++;
        }
    }
    printMap(theWordFrequencies);

    return 0;
}