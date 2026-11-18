#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<double> times = { 0, 1, 2, 3, 4, 5, 6, 7 };
    vector<double> heights = { 0, 45, 80, 105, 120, 125, 120, -5 };

    auto it = find_if(heights.begin(), heights.end(), [](double h) {
        return h <= 0.0;
        });

    if (it == heights.end()) {
        cout << "Падения не было в диапазоне.\n";
    }
    else {
        size_t idx = std::distance(heights.begin(), it);
        cout << "Момент падения: t = " << times[idx] << " с, высота = " << heights[idx] << " м\n";
    }
    return 0;
}