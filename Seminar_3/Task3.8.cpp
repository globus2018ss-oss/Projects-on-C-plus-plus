#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <string>
#include <clocale>

using namespace std;

// Структура для хранения результатов анализа полета
struct FlightStats {
    double max_height = 0.0;
    double time_of_max = 0.0;
    double time_of_fall = numeric_limits<double>::infinity(); // По умолчанию бесконечность
    bool has_fallen = false;
};

// Функция для анализа одной траектории
FlightStats analyzeTrajectory(const std::vector<double>& times, const std::vector<double>& heights) {
    FlightStats stats;
    if (heights.empty() || times.empty()) return stats;

    // 1. Поиск максимальной высоты и времени её достижения
    auto max_it = max_element(heights.begin(), heights.end());
    stats.max_height = *max_it;
    stats.time_of_max = times[distance(heights.begin(), max_it)];

    // 2. Поиск момента падения (начинаем с индекса 1, чтобы не спутать с t=0)
    if (heights.size() > 1) {
        auto fall_it = find_if(heights.begin() + 1, heights.end(), [](double h) {
            return h <= 0.0;
            });

        if (fall_it != heights.end()) {
            stats.time_of_fall = times[std::distance(heights.begin(), fall_it)];
            stats.has_fallen = true;
        }
    }

    return stats;
}

int main() {
    setlocale(LC_ALL, "RUS");
    // Тестовые данные (Ракета 1 падает, Ракета 2 всё ещё в воздухе)
    vector<double> times1 = { 0, 1, 2, 3, 4, 5, 6, 7 };
    vector<double> heights1 = { 0, 45, 80, 105, 120, 105, 80, 0 };

    vector<double> times2 = { 0, 1, 2, 3, 4 };
    vector<double> heights2 = { 0, 30, 60, 75, 80 };

    // Анализируем обе траектории
    FlightStats rocket1 = analyzeTrajectory(times1, heights1);
    FlightStats rocket2 = analyzeTrajectory(times2, heights2);

    // --- Вывод краткой таблицы сравнения ---
    cout << "Сравнение траекторий:\n";
    cout << std::string(65, '-') << "\n";

    // Заголовки колонок (единицы измерения вынесены сюда, чтобы не использовать to_string)
    cout << left << setw(25) << "Параметр"
        << setw(20) << "Ракета 1"
        << setw(20) << "Ракета 2" << "\n";
    cout << string(65, '-') << "\n";

    // Максимальная высота (м)
    cout << left << setw(25) << "Mаксимальная высота (м)"
        << setw(20) << fixed << setprecision(1) << rocket1.max_height
        << setw(20) << rocket2.max_height << "\n";

    // Время достижения максимума (с)
    cout << left << setw(25) << "Время max высоты (с)"
        << setw(20) << rocket1.time_of_max
        << setw(20) << rocket2.time_of_max << "\n";

    // Время падения (с)
    cout << left << std::setw(25) << "Время падения (с)";
    if (rocket1.has_fallen) {
        cout << setw(20) << rocket1.time_of_fall;
    }
    else {
        cout << setw(20) << "Ещё в воздухе"; // Строка выровняется благодаря setw
    }

    if (rocket2.has_fallen) {
        cout << setw(20) << rocket2.time_of_fall;
    }
    else {
        cout << setw(20) << "Ещё в воздухе";
    }
    cout << "\n" << string(65, '-') << "\n\n";

    // --- Вывод текстовых выводов ---
    // Сравнение высоты
    if (rocket1.max_height > rocket2.max_height) {
        cout << "-> Ракета 1 поднялась выше.\n";
    }
    else if (rocket2.max_height > rocket1.max_height) {
        cout << "-> Ракета 2 поднялась выше.\n";
    }
    else {
        cout << "-> Обе ракеты достигли одинаковой высоты.\n";
    }

    // Сравнение времени полета
    if (rocket1.has_fallen && rocket2.has_fallen) {
        if (rocket1.time_of_fall > rocket2.time_of_fall)
            cout << "-> Ракета 1 находилась в воздухе дольше.\n";
        else if (rocket2.time_of_fall > rocket1.time_of_fall)
            cout << "-> Ракета 2 находилась в воздухе дольше.\n";
        else
           cout << "-> Обе ракеты упали одновременно.\n";
    }
    else if (rocket1.has_fallen && !rocket2.has_fallen) {
        cout << "-> Ракета 2 всё ещё в воздухе, следовательно, она летит дольше Ракеты 1.\n";
    }
    else if (!rocket1.has_fallen && rocket2.has_fallen) {
        cout << "-> Ракета 1 всё ещё в воздухе, следовательно, она летит дольше Ракеты 2.\n";
    }
    else {
        cout << "-> Обе ракеты всё ещё находятся в воздухе, точное время падения неизвестно.\n";
    }

    return 0;
}