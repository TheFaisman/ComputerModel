#include <iostream>

enum Voltage {
    Strong_Low = 0,
    Weak_Low,
    High_Z,
    Weak_High,
    Strong_High
};

// Create a synonym for a pointer to a voltage; Terminal
typedef Voltage* Terminal;

class Transistor {
protected:
    Terminal drain_;
    Terminal gate_;
    Terminal source_;

    bool conducting_;

    Voltage const threshold_ = Weak_High;

public:
    Transistor(Terminal drain, Terminal gate, Terminal source) : drain_(drain), gate_(gate), source_(source) {
        std::cout << "Transistor constructor executed." << std::endl;
    }

    Voltage ReadGate() { return *gate_; }
    Voltage ReadSource() { return *source_; }
    Voltage ReadDrain() { return *drain_; }

    void SetGateVoltage(Voltage gate_voltage);
};


