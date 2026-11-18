#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<int> sensor_data = { 0, 5, 0, 1, 0, 0, 9 };
    int zero_count = count(sensor_data.begin(), sensor_data.end(), 0);
    cout << "Количество нулевых показаний: " << zero_count << "\n";
    return 0;
}