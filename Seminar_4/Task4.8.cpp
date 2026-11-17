#include <iostream>
#include <clocale>

using namespace std;

class NavigationSystem {
private:
    double x, y;
    double velocityX, velocityY;
    bool gpsAvailable;
public:
    NavigationSystem(double x0, double y0, double vx, double vy, bool gps)
        : x(x0), y(y0), velocityX(vx), velocityY(vy), gpsAvailable(gps) {
    }

    void integratePosition(double dt) {
        x += velocityX * dt;
        y += velocityY * dt;
    }

    void correctGPS(double realX, double realY) {
        if (gpsAvailable) {
            x = (x + realX) / 2.0;
            y = (y + realY) / 2.0;
        }
    }

    void printPosition() const {
        cout << "Скорректированные координаты: (" << x << ", " << y << ")\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    NavigationSystem nav(0, 0, 100, 50, true);
    nav.integratePosition(1);
    nav.correctGPS(110, 60);
    nav.printPosition();
    return 0;
}