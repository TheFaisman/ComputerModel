enum LogicLevel {
    Strong_Low = 0,
    Weak_Low,
    High_Z,
    Weak_High,
    Strong_High
};

class Transistor {
private:
    LogicLevel drain_;
    LogicLevel gate_;
    LogicLevel source_;

    LogicLevel threshold_;

public:
    Transistor(LogicLevel drain, LogicLevel gate, LogicLevel source) : drain_(drain), gate_(gate), source_(source) {};
};

class NMOS : public Transistor {

};

class PMOS : public Transistor {

};