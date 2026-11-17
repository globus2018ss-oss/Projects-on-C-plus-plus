#include <iostream>
#include <clocale>

using namespace std;

class Autopilot {
private:
    double courseAngle;
    double altitude;
public:
    Autopilot(double angle, double alt) : courseAngle(angle), altitude(alt) {}

    void changeCourse(double delta) { courseAngle += delta; }
    void changeAltitude(double delta) { altitude += delta; }

    void printStatus() const {
        cout << "Курс: " << courseAngle << "°, высота: " << altitude << " м\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Autopilot a1(90, 1000);
    a1.changeCourse(10);
    a1.changeAltitude(500);
    a1.printStatus();
    return 0;
}