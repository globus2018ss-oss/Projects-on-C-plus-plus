/*Задача 8
Условие:
Есть массив струтур Aircraft, содержащих параметры каждого самолёта:
масса, тяга, коэффициенты подъёмной и сопротивления силы
Требуется: 
Для каждого самолёта вычислить вертикальное ускорение и время набора заданной высоты h*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <clocale>



using namespace std;

struct Aircraft {
    string name;
    double m, T, CL, CD;
};

int main() {

    setlocale(LC_ALL, "RUS");

    double rho = 1.225;
    double V = 200.0;
    double S = 20.0; // Примем площадь крыла одинаковой для всех
    double g = 9.81;
    double h = 1000.0;

    vector<Aircraft> planes = {
        {"Aerobus-1", 1000, 5000, 0.5, 0.05},
        {"Aroflot-3957", 1200, 6000, 0.6, 0.04},
        {"Boeing-777", 900, 4500, 0.45, 0.06}
    };

    // Расчет времени для каждого
    for (auto& p : planes) {
        double L = 0.5 * rho * V * V * S * p.CL;
        double ay = (L - p.m * g) / p.m;
        double t = (ay > 0) ? sqrt(2 * h / ay) : 1e9; // Если ay <= 0, время бесконечно

        // Сохраним время (можно добавить поле в структуру или использовать отдельный вектор, 
        // для простоты пересчитаем при выводе или добавим поле)
        // Для сортировки добавим поле time в структуру
    }

    // Добавим поле time в структуру для сортировки
    struct AircraftWithTime {
        string name;
        double t;
    };
    vector<AircraftWithTime> results;

    for (const auto& p : planes) {
        double L = 0.5 * rho * V * V * S * p.CL;
        double ay = (L - p.m * g) / p.m;
        double t = (ay > 0) ? sqrt(2 * h / ay) : 1e9;
        results.push_back({ p.name, t });
    }

    // Сортировка по времени
    sort(results.begin(), results.end(), [](const AircraftWithTime& a, const AircraftWithTime& b) {
        return a.t < b.t;
        });

    cout << "Результаты (отсортированы по времени набора высоты):" << endl;
    for (const auto& res : results) {
        cout << res.name << ": " << res.t << " с" << endl;
    }

    return 0;
}