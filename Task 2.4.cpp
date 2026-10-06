/*Задача 4
Условие:
Если вертикальная скорость самолёта определяется ускорением a_y, рассчитать время t, 
необходиоме для набора заднной высоты h по формуле движения с постоянным ускорением: h=1/2*a_y*t^2
Требуется:
Написать программу на C++, которая запрашивает h и вычисляет t.*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main(){

    setlocale(LC_ALL, "RUS");
    double h, a_y;
    cout << "Введите высоту h: ";
    cin >> h;
    cout << "Введите вертикальное ускорение a_y: ";
    cin >> a_y;
    if (h <= 0 || a_y <= 0) {
        cout << "Ошибка ввода данных, попробуйте ещё раз" << endl;
        return 1;
    }
    double t = sqrt(2 * h / a_y);
    cout << "Dремя, необходиме для набора высоты t = "<<fixed<<setprecision(2)<<t;
}


