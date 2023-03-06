#include "headers/simple_iteration.h"
#include "../headers/equations.h"
using namespace std;
using ld = long double;

bool is_series_converges(ld a, ld b, ld lambda, equation d){
    ld phi_a = 1 + lambda * d(a);
    ld phi_b = 1 + lambda * d(b);
    return phi_a < 1 && phi_b < 1;

}

ld phi(ld x, ld lambda, equation f){
    return x + lambda * f(x);
}

void solve(ld x0, ld a, ld b, int eq, ld eps=1e-3){
    vector<equation>f = get_equations();
    vector<equation>d = get_derivatives();
    ld lambda = -(1/max(d[eq](a), d[eq](b)));
    if(!is_series_converges(a, b, lambda, d[eq])){
        cout << "Метод простой итерации будет расходиться на данном интервале" << endl;
        return;
    }
    ld x1 = phi(x0, lambda, f[eq]);
    //cout << setprecision(3) << fixed;
    //cout << x0 << ' ' << x1 << ' ' << phi(x1, lambda, f[eq]) << ' ' << f[eq](x1) << ' ' << abs(x0 - x1) << endl;
    int iteration = 1;
    while(abs(x1 - x0) > eps){
        x0 = x1;
        x1 = phi(x1, lambda, f[eq]);
        //cout << setprecision(3) << fixed;

        //cout << x0 << ' ' << x1 << ' ' << phi(x1, lambda, f[eq]) << ' ' << f[eq](x1) << ' ' << abs(x0 - x1) << endl;

        iteration++;
    }
    cout << setprecision(10) << fixed;
    cout << "Метод простой итерации" << endl;
    cout << "Корень на отрезке от " << a << " до " << b << ": " << x1 << endl;
    cout << "Значение функции в точке " << x1 << ": " << f[eq](x1) << endl;
    cout << "Количество итераций, потребовавшихся для вычисления: " << iteration << endl;
}
void simple_iteration(int eq){
    pair<ld, ld>interval = choose_interval(eq);
    cout << "Введите начальное приближение к корню" << endl;
    ld x0;
    cin >> x0;
    solve(x0,  interval.first, interval.second, eq);
}
