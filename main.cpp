#include <iostream>
#include "transistor_api.hpp"

Voltage constexpr VDD = Strong_High;
Voltage constexpr VSS = Strong_Low;

int main() {
    Voltage source_voltage = Strong_Low;
    Voltage gate_voltage = Strong_High;
    Voltage drain_voltage = High_Z;

    NMOS transistor{drain_voltage, gate_voltage, source_voltage};

    transistor.DumpTerminalAddresses();
    std::cout << std::endl;
    transistor.PrintVoltages();
    return 0;
}