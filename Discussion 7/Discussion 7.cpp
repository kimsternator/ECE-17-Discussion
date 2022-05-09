#include <iostream>
#include <string>

using std::string;

// Data
class Coordinates {};
// Models
class Volcano {};
// Relationships
class UserAccount {};
class Account {};
class CheckingAccount : public Account {};
class SavingAccount : public Account {};
class Bank {};
// Functor
class Button {};
// Interface
class INodeVisitor {};
// Process
class JSONObject {};
class HTTP {
    enum class HTTPCODES { STATUS_200 = 200, STATUS_401 = 401, STATUS_404 = 404 };
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
};
// Utilities
class Printer {};

int main() {

    return 0;
}
