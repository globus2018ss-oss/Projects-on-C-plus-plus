#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<double> h = { 0, 10, 25, 35, 40, 45, 30, 20, 5 };
    vector<double> smoothed(h.size());

    for (size_t i = 0; i < h.size(); ++i) {
        double sum = h[i];
        int count = 1;

        if (i > 0) { sum += h[i - 1]; count++; }
        if (i < h.size() - 1) { sum += h[i + 1]; count++; }

        smoothed[i] = sum / count;
    }

    cout << setw(10) << "Исходная" << setw(15) << "Сглаженная" << "\n";
    for (size_t i = 0; i < h.size(); ++i) {
        cout << setw(10) << h[i]
            << setw(15) << fixed << setprecision(2) << smoothed[i] << "\n";
    }
    return 0;
}