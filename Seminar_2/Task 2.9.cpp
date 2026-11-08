/*Задача 9
Условие:
Пользователь вводит несколько конфигураций самолёта: количество самолётов N, 
затем для каждого - масса, площадь крыла, тягаб CL, CD
Требуется:
Расситать подъёмную силу, сопротивление и ускорение для каждого самолёта*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <clocale>


using namespace std;

struct Aircraft {
    string name;
    double m, S, T, CL, CD;
};

int main() {

    setlocale(LC_ALL, "RUS");

    int N;
    cout << "Введите количество самолетов N: ";
    cin >> N;

    vector<Aircraft> planes(N);
    double rho = 1.225;
    double V = 200.0;
    double g = 9.81;

    for (int i = 0; i < N; i++) {
        cout << "\nСамолет " << i + 1 << ":" << endl;
        cout << "Имя: ";
        cin >> planes[i].name;
        cout << "Масса: ";
        cin >> planes[i].m;
        cout << "Площадь крыла: ";
        cin >> planes[i].S;
        cout << "Тяга: ";
        cin >> planes[i].T;
        cout << "CL: ";
        cin >> planes[i].CL;
        cout << "CD: ";
        cin >> planes[i].CD;
    }

    double maxAccel = -1e9;
    string leader;

    cout << "\n--- Результаты ---" << endl;
    for (const auto& p : planes) {
        double L = 0.5 * rho * V * V * p.S * p.CL;
        double D = 0.5 * rho * V * V * p.S * p.CD;
        double a = (p.T - D) / p.m;

        cout << p.name << ": Подъемная сила = " << L
            << ", Сопротивление = " << D
            << ", Ускорение = " << a << " м/с^2" << endl;

        if (a > maxAccel) {
            maxAccel = a;
            leader = p.name;
        }
    }

    cout << "\nНаибольшее ускорение у самолета: " << leader << " (" <<fixed<<setprecision(2)<< maxAccel << " м/с^2)" << endl;

    return 0;
}