#include <iostream>

#include "Notebook.hpp"

int main() {
    Notebook theNotebook{{
        Page{"One", 1},
        Page{"Two", 2},
        Page{"Three", 3}
    }};

    return 0;
}