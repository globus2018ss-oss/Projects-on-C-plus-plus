#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

void remove_low_heights(std::vector<double>& heights) {
    // remove_if переставляет элементы, возвращая итератор на "новый конец"
    auto new_end = std::remove_if(heights.begin(), heights.end(), [](double h) {
        return h < 10.0;
        });
    // erase физически удаляет элементы
    heights.erase(new_end, heights.end());
}

int main() {
    setlocale(LC_ALL, "RUS");
    vector<double> heights = { 0, 15, 5, 22, 8, 50, 3, 12 };

    remove_low_heights(heights);

    cout << "Оставшиеся высоты: ";
    for (double h : heights) {
        cout << h << " ";
    }
    cout << "\n";
    return 0;
}