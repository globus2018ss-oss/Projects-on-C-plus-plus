#include <iostream>
#include <clocale>

using namespace std;

class Engine {
private:
    double thrust;
    double fuelFlow;
public:
    Engine(double T, double F) : thrust(T), fuelFlow(F) {}

    double getSpecificImpulse() const {
        return thrust / (fuelFlow * 9.81);
    }

    void printInfo() const {
        cout << "Тяга: " << thrust << " Н | Расход: " << fuelFlow
            << " кг/с | Удельный импульс: " << getSpecificImpulse() << " с\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Engine e1(5000, 2.5);
    e1.printInfo();
    return 0;
}