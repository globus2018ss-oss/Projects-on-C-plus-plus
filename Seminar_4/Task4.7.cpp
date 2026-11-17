#include <iostream>
#include <clocale>

using namespace std;

class FlightComputer {
private:
    double altitude;
    double velocity;
    double fuel;
    double thrust;
    double time;
public:
    FlightComputer(double alt, double vel, double f, double t)
        : altitude(alt), velocity(vel), fuel(f), thrust(t), time(0) {
    }

    void simulateStep(double dt) {
        time += dt;
        velocity += (thrust / 1000.0 - 9.8) * dt;
        altitude += velocity * dt;
        fuel -= dt * 2.0;
    }

    void printStatus() const {
        cout << "t=" << time << "c: высота=" << altitude << "м, скорость="
            << velocity << "м/с, топливо=" << fuel << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    FlightComputer fc(0, 0, 100, 12000);
    for (int i = 0; i < 5; ++i) {
        fc.simulateStep(0.5);
        fc.printStatus();
    }
    return 0;
}