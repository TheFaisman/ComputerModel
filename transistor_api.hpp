#include <iostream>

enum LogicLevel {
    Strong_Low = 0,
    Weak_Low,
    High_Z,
    Weak_High,
    Strong_High
};

class Transistor {
protected:
    LogicLevel drain_;
    LogicLevel gate_;
    LogicLevel source_;

    bool conducting_;

    LogicLevel const threshold_ = Weak_High;

public:
    Transistor(LogicLevel drain, LogicLevel gate, LogicLevel source) : drain_(drain), gate_(gate), source_(source) {
        std::cout << "Transistor constructor executed." << std::endl;
    }

    LogicLevel ReadGate() { return gate_; }
    LogicLevel ReadSource() { return source_; }
    LogicLevel ReadDrain() { return drain_; }

    void SetGate(LogicLevel gate) {
        this->gate_ = gate;
        if (this->gate_ >= threshold_) {
            this->conducting_ = true;
            this->drain_ = this->source_;
        } else {
            this->drain_ = High_Z;
            this->conducting_ = false;
        }
    }
};

class NMOS : public Transistor {
private:
    

public:

};

