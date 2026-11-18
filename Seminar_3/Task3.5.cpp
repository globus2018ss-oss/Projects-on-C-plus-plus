#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

struct Point { double x, y, z; };

int main() {
    setlocale(LC_ALL, "RUS");
    vector<Point> traj;
    traj.reserve(20); // Резервируем память

    double vx = 30.0, vy = 20.0, vz = 40.0;
    double x = 0.0, y = 0.0, z = 0.0;
    double dt = 1.0;
    double t_max = 5.0;

    for (double t = 0.0; t <= t_max; t += dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        traj.push_back({ x, y, z });
    }

    cout << std::setw(8) << "t" << std::setw(10) << "X" << std::setw(10) << "Y" << std::setw(10) << "Z" << "\n";
    for (size_t i = 0; i < traj.size(); ++i) {
        cout << setw(8) << i * dt
            << setw(10) << traj[i].x
            << setw(10) << traj[i].y
            << setw(10) << traj[i].z << "\n";
    }
    return 0;
}