#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<double> y_coords = { 0.0, 10.0, 25.0, 20.0, 40.0 };
    vector<double> diffs(y_coords.size());

    // Находит разности соседних элементов: diffs[0]=0, diffs[1]=y[1]-y[0] и т.д.
    adjacent_difference(y_coords.begin(), y_coords.end(), diffs.begin());

    // Начинаем с diffs.begin() + 1, так как diffs[0] содержит исходный y[0], а не разность
    double total_path = accumulate(diffs.begin() + 1, diffs.end(), 0.0,
        [](double acc, double diff) { return acc + abs(diff); });

    cout << "Суммарный путь: " << total_path << "\n";
    return 0;
}