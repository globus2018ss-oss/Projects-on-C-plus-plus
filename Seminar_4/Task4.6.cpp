#include <iostream>
#include <clocale>

using namespace std;

class RocketStage {
private:
    double thrust;
    double burnTime;
    double mass;
public:
    RocketStage(double T, double B, double M) : thrust(T), burnTime(B), mass(M) {}

    double getDeltaV() const {
        return (thrust * burnTime) / mass;
    }

    void printInfo() const {
        cout << "Тяга: " << thrust << " Н | Время: " << burnTime
            << " с | Масса: " << mass << " кг | dV: " << getDeltaV() << " м/с\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    RocketStage s1(5000, 10, 1000);
    RocketStage s2(7000, 8, 900);
    RocketStage s3(9000, 6, 800);

    double totalV = s1.getDeltaV() + s2.getDeltaV() + s3.getDeltaV();
    std::cout << "Итоговая скорость ракеты: " << totalV << " м/с\n";
    return 0;
}