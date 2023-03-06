#include "headers/binary_division.h"
#include "../headers/equations.h"



static void solve(ld a, ld b, int eq, const ld eps = 1e-3){
    ld old_a = a, old_b = b;
    vector<equation>f= get_equations();
    int iteration = 0;
    while(abs(b - a) > eps){
        iteration++;
        ld x = (a + b) / 2;
        cout << setprecision(3) << fixed;
        //cout << a << ' ' << b << ' ' << x << ' ' << f[eq](a) << ' ' << f[eq](b) << ' ' << f[eq](x) << ' ' << abs(a-b) << endl;
        if(abs(x) < eps) break;
        if(f[eq](a) * f[eq](x) > 0) a = x;
        else b = x;

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

