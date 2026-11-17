#include <iostream>
#include <clocale>

using namespace std;

class Engine {
private:
    double thrust;
    double fuelFlow;
    double fuel;
public:
    Engine(double t, double ff, double f) : thrust(t), fuelFlow(ff), fuel(f) {}

    double getThrust() const { return thrust; }
    bool hasFuel() const { return fuel > 0.0; }
    double getFuel() const { return fuel; }

    void burn(double dt) {
        if (hasFuel()) {
            fuel -= fuelFlow * dt;
            if (fuel < 0) fuel = 0;
        }
    }
};

class Navigation {
private:
    double altitude;
    double velocity;
    double acceleration;
    double mass;
public:
    Navigation(double alt, double vel, double m)
        : altitude(alt), velocity(vel), acceleration(0), mass(m) {
    }

    void update(double thrust, double dt) {
        acceleration = (thrust / mass) - 9.81;
        // Сначала обновляем высоту на основе текущей скорости, затем скорость
        altitude += velocity * dt;
        velocity += acceleration * dt;
    }

    void printStatus(double time) const {
        std::cout << "t=" << time << "c | h=" << altitude << "m | v="
            << velocity << "m/c | a=" << acceleration << "m/c^2\n";
    }
};

class AutonomousFlightSystem {
private:
    Engine engine;
    Navigation nav;
    double time;
public:
    AutonomousFlightSystem(const Engine& e, const Navigation& n)
        : engine(e), nav(n), time(0) {
    }

    void simulate(double dt, double totalTime) {
        while (time < totalTime && engine.hasFuel()) {
            engine.burn(dt);
            nav.update(engine.getThrust(), dt);
            nav.printStatus(time);
            time += dt;
        }
        cout << "--- Полет завершен ---\n";
        cout << "Оставшееся топливо: " << engine.getFuel() << " кг\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Engine e(20000, 10, 1000);
    Navigation n(0, 0, 1000);
    AutonomousFlightSystem sys(e, n);
    sys.simulate(1.0, 5.0);
    return 0;
}