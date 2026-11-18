#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    // Данные из задачи 3
    vector<double> velocities = { 50.0, 40.2, 30.4, 20.6, 10.8, 1.0, -8.8 };

    if (velocities.empty()) {
        cout << "Данных нет.\n";
        return 0;
    }

    // Передаем 0.0, чтобы accumulate работал именно с double
    double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();

    cout << "Средняя скорость: " << fixed << setprecision(2) << avg << " м/с\n";
    return 0;
}