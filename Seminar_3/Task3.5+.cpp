#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<double> x_coords = { 3.5, 1.2, 3.5, 2.1, 1.2, 4.0 };

    sort(x_coords.begin(), x_coords.end());
    // unique возвращает итератор на начало "мусора" в конце
    x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

    cout << "Уникальные координаты: ";
    for (double x : x_coords) cout << x << " ";
    cout << "\n";
    return 0;
}