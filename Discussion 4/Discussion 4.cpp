#include <iostream>

#include "Notebook.hpp"

/* Trick for deleting entire Linked List
~Node::Node() {
    delete _next;
}
Node* _next;
*/

int main() {
    Notebook theNotebook{{
        Page{"One", 1},
        Page{"Two", 2},
        Page{"Three", 3}
    }};

    

    // Calls default constructor
    Notebook aNotebook;
    // parameter
    Notebook aNotebook1({});
    // Copy
    Notebook aNotebook2(theNotebook);
    // Assignment
    Notebook aNotebook3 = aNotebook1;
    // Index Operator
    theNotebook[0]; // Page{"One", 1}

    return 0;
}