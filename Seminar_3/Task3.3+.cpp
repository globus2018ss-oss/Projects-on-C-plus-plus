#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<double> temps = { 50.0, -150.0, 80.0, 250.0, 22.0, -50.0 };

    temps.erase(remove_if(temps.begin(), temps.end(),
        [](double t) { return t < -100 || t > 200; }), temps.end());

    cout << "Очищенные данные: ";
    for (double t : temps) cout << t << " ";
    cout << "\n";
    return 0;
}