#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    const double v0 = 50.0;
    const double g = 9.8;
    vector<double> times = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

    vector<double> velocities;
    velocities.reserve(times.size()); // Оптимизация

    for (double t : times) {
        double v = v0 - g * t;
        velocities.push_back(v);
    }

    cout << std::setw(10) << "Время (с)" << std::setw(15) << "Скорость (м/с)" << "\n";
    cout << std::string(25, '-') << "\n";
    for (size_t i = 0; i < times.size(); ++i) {
        cout << std::setw(10) << fixed << setprecision(1) << times[i]
            << setw(15) << fixed << setprecision(2) << velocities[i] << "\n";
    }
    return 0;
}