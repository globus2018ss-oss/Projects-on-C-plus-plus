#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "RUS");

    double T, L, D, m;
    const double g = 9.81;

    cout << "Введите тягу T: ";
    cin >> T;
    cout << "Введите подъемную силу L: ";
    cin >> L;
    cout << "Введите сопротивление D: ";
    cin >> D;
    cout << "Введите массу самолета m: ";
    cin >> m;

    double ay = (L - m * g) / m;

    cout << "Вертикальное ускорение: " <<fixed<<setprecision(2)<< ay << " м/с^2" << endl;
    cout << "Режим полета: ";

    if (ay > 0.5) {
        cout << "набор высоты" << endl;
    }
    else if (ay >= 0 && ay <= 0.5) {
        cout << "горизонтальный полет" << endl;
    }
    else {
        cout << "снижение" << endl;
    }

    return 0;
}