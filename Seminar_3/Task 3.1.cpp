#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    vector<double> times;
    vector<double> heights;

    // Оптимизация памяти: примерный размер = (полное время полета) / dt + 2
    size_t estimated_size = static_cast<size_t>((2.0 * v0 / g) / dt) + 2;
    times.reserve(estimated_size);
    heights.reserve(estimated_size);

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) break; // Ракета упала
        times.push_back(t);
        heights.push_back(h);
    }

    cout << setw(10) << "Время (с)" << setw(15) << "Высота (м)" << "\n";
    cout << string(25, '-') << "\n";
    for (size_t i = 0; i < times.size(); ++i) {
        cout << setw(10) << fixed << setprecision(1) << times[i]
            << setw(15) << fixed << setprecision(2) << heights[i] << "\n";
    }
    return 0;
}