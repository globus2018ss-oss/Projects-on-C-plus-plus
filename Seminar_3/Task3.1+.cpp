#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL,"RUS");
    vector<double> heights = { 10.5, 50.2, 120.8, 80.1, 30.4 };
    auto max_it = std::max_element(heights.begin(), heights.end());
    cout << "Максимальная высота: " << *max_it << " м\n";
    return 0;
}