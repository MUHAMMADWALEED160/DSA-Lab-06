#include<iostream>
#include<cmath>  // For sqrt function
using namespace std;

// Base class: Progression
class Progression {
    protected:
        double a;  // Start value for progression

    public:
        // Default constructor initializes 'a' with 65536
        Progression() : a(65536) {}

        // Parametric constructor initializes 'a' with a given value
        Progression(double start) : a(start) {}

        // Method to return the current value of 'a'
        double getValue() const {
            return a;
        }
};

// Derived class: FinalProgression
class FinalProgression : public Progression {
    public:
        // Default constructor uses base class constructor
        FinalProgression() : Progression() {}

        // Parametric constructor to start with a specified value
        FinalProgression(double start) : Progression(start) {}

        // Method to compute next value as the square root of the current one
        void nextValue() {
            a = sqrt(a);  // Update 'a' to its square root
        }
};

int main() {
    FinalProgression p;  // Start with default 65536
    cout << "Initial value: " << p.getValue() << endl;

    p.nextValue();  // Take square root
    cout << "After one progression: " << p.getValue() << endl;

    return 0;
}
