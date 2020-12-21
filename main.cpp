#include <iostream>
#include "transistor_api.hpp"

int main() {
    Transistor nmos{Strong_High, High_Z, Strong_Low};
    nmos.SetGate(Strong_High);
    return 0;
}