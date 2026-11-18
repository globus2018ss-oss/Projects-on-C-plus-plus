#include <iostream>
#include <vector>
#include <clocale>

using namespace std;

struct Point { double x, y, z; };

class Rocket {
public:
    Point pos{ 0, 0, 0 };
    double vx, vy, vz;

    Rocket(double vx, double vy, double vz) : vx(vx), vy(vy), vz(vz) {}

    void updatePosition(double dt) {
        pos.x += vx * dt;
        pos.y += vy * dt;
        pos.z += vz * dt;
    }
    Point getPosition() const { return pos; }
};

int main() {
    setlocale(LC_ALL, "RUS");
    vector<Rocket> squad;
    squad.reserve(5); // Обязательно резервируем!

    // emplace_back создает объект прямо в памяти вектора
    squad.emplace_back(1000, 10, 0);
    squad.emplace_back(900, 15, -5);
    squad.emplace_back(800, 20, 10);
    squad.emplace_back(700, 25, -10);
    squad.emplace_back(600, 30, 5);

    double dt = 1.0;
    double T = 10.0;

    for (double t = 0.0; t <= T; t += dt) {
        for (auto& rocket : squad) { // Передача по ссылке, чтобы менять объекты
            rocket.updatePosition(dt);
        }
    }

    cout << "Конечные положения ракет через " << T << " секунд:\n";
    for (size_t i = 0; i < squad.size(); ++i) {
        Point p = squad[i].getPosition();
        cout << "Ракета " << i + 1 << ": X=" << p.x << ", Y=" << p.y << ", Z=" << p.z << "\n";
    }
    return 0;
}