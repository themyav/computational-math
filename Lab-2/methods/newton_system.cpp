#include "headers/newton_system.h"
#include "../headers/gauss.h"

const int SIZE = 2;

void solve_sys(ld x0, ld y0, int sys, ld eps=0.01){
    vector<pair<equation2, equation2>>systems = get_systems();
    vector<pair<equation2, equation2>>system_dx = get_systems_dx();
    vector<pair<equation2, equation2>>system_dy = get_systems_dy();
    vector<ld> x(SIZE, 0);
    int iteration = 0;
    while(true){
        vector<vector<ld>>matrix = {
                {system_dx[sys].first(x0, y0), system_dy[sys].first(x0, y0)},
                {system_dx[sys].second(x0, y0), system_dy[sys].second(x0, y0)}
        };
        vector<ld>b = {
                -systems[sys].first(x0, y0), -systems[sys].second(x0, y0)
        };
        //print_matrix(SIZE, matrix);
        //print_vector(SIZE, b, "b");
        x = gauss(SIZE, matrix, b);
        x[0] += x0;
        x[1] += y0;
        iteration++;
        if(abs(x[0] - x0) <= eps && abs(x[1] - y0) <= eps) break;
        x0 = x[0]; y0 = x[1];
    }
    cout << setprecision(10) << fixed;
    cout << "Решение системы нелинейных уравнений методом Ньютона" << endl;
    cout << "Вектор неизвестных: x = " << x[0] << ", y = " << x[1] << endl;
    cout << "Вектор погрешностей: Δx = " << abs(x0 - x[0]) << ", Δy = " << abs(y0 - x[1]) << endl;
    cout << "Проверим решение системы: подставим значения x = " << x[0] << ", y = " << x[1] << " в преобразованные уравнения" << endl;
    cout << "Получим: " << systems[sys].first(x[0], x[1]) << ' ' << systems[sys].second(x[0], x[1]) << endl;
    cout << "Количество итераций, потребовавшихся для вычисления: " << iteration << endl;



}

void newton_system(int sys){
    cout << "Введите начальное приближение" << endl;
    ld x0, y0;
    cin >> x0 >> y0;
    solve_sys(x0, y0, sys);
}
