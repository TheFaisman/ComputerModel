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
    bool is_conducting;

public:
    ~Transistor() {
        std::cout << "Base class destructor called.\n";
        delete this->drain_;
        delete this->gate_;
        delete this->source_;
    }

    // Getter functions
    inline Voltage ReadGateVoltage() {
        return *(this->gate_);
    }
    inline Voltage ReadSourceVoltage() {
        return *(this->source_); 
    }
    inline Voltage ReadDrainVoltage() {
        return *(this->drain_); 
    }
    inline bool IsConducting() {
        return is_conducting;
    }

    // Debug functions
    void DumpTerminalAddresses() {
        std::cout << "Drain address:\t" << this->drain_ << std::endl;
        std::cout << "Gate address:\t" << this->gate_ << std::endl;
        std::cout << "Source address:\t" << this->source_ << std::endl;
    }
    void PrintVoltages() {
        std::cout << "Drain voltage:\t" << this->ReadDrainVoltage() << std::endl;
        std::cout << "Gate voltage:\t" << this->ReadGateVoltage() << std::endl;
        std::cout << "Source voltage:\t" << this->ReadSourceVoltage() << std::endl;
    }
};

class NMOS : public Transistor {
private:
    Voltage constexpr static V_threshold = Weak_High;
    Voltage V_gs;

public:
    NMOS(Voltage drain_voltage, Voltage gate_voltage, Voltage source_voltage) {
        this->drain_ = new Voltage(drain_voltage);
        this->gate_ = new Voltage(gate_voltage);
        this->source_ = new Voltage(source_voltage);
        this->UpdateState();
    }

    inline Voltage DetermineVGS() {
        return Voltage(this->ReadGateVoltage() - this->ReadSourceVoltage());
    }

    void UpdateState() {
        this->V_gs = DetermineVGS();
        if (V_gs >= V_threshold) {
            this->is_conducting = true;
            delete this->drain_;
            this->drain_ = this->source_;
        } else {
            this->is_conducting = false;
        }
    }
};

