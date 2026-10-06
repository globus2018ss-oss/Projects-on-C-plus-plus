/* Задача 5
Условие:
Есть три разных самолёта с заданными параметрами(масса,площадь крыла, тяга,CD, CL)
Требуется:
Написать программу, которая для каждого самолёта вычисляет подъёмную силу, сопротивление и ускорение,
а затем выводит, какой самолёт быстрее наьерёт высоту h*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <clocale>

using namespace std;

struct Aircraft{
    string name;
    double m; //масса
    double S; //площадь крыла
    double T; // тяга
    double CL; //коэффициент подъёмной силы
    double CD; //коэффициент сопротивления
};


int main(){

    setlocale(LC_ALL, "RUS");
    const double g = 9.81;
    const double V = 200.0;
    const double ro = 1.225;
    const double h = 1540.0;

    Aircraft planes[3] = {
        {"Aerobus-1", 1000, 16, 5000, 0.5, 0.05},
        {"Aeroflot-5940", 1500, 23, 6000, 0.6, 0.04},
        {"Boeing-777", 800, 12, 4000,0.4, 0.06}
    };

    double minTime = 1e9;
    string fastestPlane;

    for (int i = 0; i < 3; i++) { //расчитываем для каждого самолёта подъёмную силу, сопротивление, ускорение
        double L = 0.5 * ro * pow(V, 2) * planes[i].S * planes[i].CL;
        double D = 0.5 * ro * pow(V, 2) * planes[i].S * planes[i].CD;
        double ay = (L - planes[i].m * g) / planes[i].m;

        cout << "--- " << planes[i].name << " ---" << endl;
        cout << "Подъемная сила: " << L << " Н" << endl;
        cout << "Сопротивление: " << D << " Н" << endl;
        cout << "Вертикальное ускорение: " << ay << " м/с^2" << endl;

        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            cout << "Время набора высоты " << h << " м: " << t << " с" << endl;
            if (t < minTime) { // стандартная проверка на минимум
                minTime = t;
                fastestPlane = planes[i].name;
            }
        }
        else {
            cout << "Самолет не может набрать высоту (ay <= 0)" << endl; //проверка на a_y>0
        }
    }

    cout << "\nБыстрее всех высоту наберет: " << fastestPlane << " за " << minTime << " с" << endl;
}

