#include <iostream>
#include <vector>
#include <cmath>
#include <clocale>

using namespace std;

class DroneFlight {
private:
    std::vector<double> x, y;
    double totalDistance;
public:
    DroneFlight() : totalDistance(0) {}

    void addPoint(double newX, double newY) {
        if (!x.empty()) {
            double dx = newX - x.back();
            double dy = newY - y.back();
            totalDistance += std::sqrt(dx * dx + dy * dy);
        }
        x.push_back(newX);
        y.push_back(newY);
    }

    double getTotalDistance() const { return totalDistance; }

    void printPath() const {
        cout << "Точки маршрута:\n";
        for (size_t i = 0; i < x.size(); ++i) {
            cout << "(" << x[i] << ", " << y[i] << ")\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    DroneFlight d;
    d.addPoint(0, 0);
    d.addPoint(3, 4);
    d.addPoint(6, 8);
    d.printPath();
    cout << "Пройдено: " << d.getTotalDistance() << " м\n";
    return 0;
}