/*Задача 2.
Условие:
ДЛя того же самлёта вычислить аэродинамическое соопротивление по формуле: L= 1/2*ro*V^2*S*CD, где СВ - коэффициент сопротивления
Требуется:
Создать отдельную функцию в С++ для расчёта сопротивления, приянть параметры через аргументы функци, вывести результат*/

#include <iostream>
#include <cmath> //см. Task1
#include <iomanip> //см. Task1
#include <clocale> //см. Task1

using namespace std;

double drag_force_calculator(double x, double y, double z, double a) {
    double F = 0.5 * z * pow(y, 2) * x * a;
    return F;
}

int main() {

    setlocale(LC_CTYPE, "RUS");

    double S, V, ro, CD;

    //Вводим наши данные:
    cout << "Введите площадь крыла S: ";
    cin >> S;
    cout << "Введите скорость полета V: ";
    cin >> V;
    cout << "Введите плотность воздуха ro: ";
    cin >> ro;
    cout << "Введите коэффициент сопротивления CD: ";
    cin >> CD;
    cout << "Cила сопротивления L = " << fixed << setprecision(3) << drag_force_calculator(S, V, ro, CD) << " Н" << endl;
    return 0;
}
