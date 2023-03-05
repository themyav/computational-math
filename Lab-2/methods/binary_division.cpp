#include "headers/binary_division.h"
#include "../headers/equations.h"



static void solve(ld a, ld b, int eq, const ld eps = 1e-3){
    ld old_a = a, old_b = b;
    vector<equation>f= get_equations();
    int iteration = 0;
    while(b - a > eps){
        iteration++;
        ld x = (a + b) / 2;
        if(abs(x) < eps) break;
        if(f[eq](a) * f[eq](b) > 0) a = x;
        else b = x;
        cout << a << ' ' << b << ' ' << f[eq](a) << ' ' << f[eq](b) << endl;
    }
    ld x = (a + b) / 2;
    cout << setprecision(10) << fixed;
    cout << "Метод половинного деления" << endl;
    cout << "Корень на отрезке от " << old_a << " до " << old_b << ": " << x << endl;
    cout << "Значение функции в точке " << x << ": " << f[eq](x) << endl;
    cout << "Количество итераций, потребовавшихся для вычисления: " << iteration << endl;
}

void binary_division(int eq){
    pair<ld, ld>interval = choose_interval(eq);
    solve(interval.first, interval.second, eq);
}

