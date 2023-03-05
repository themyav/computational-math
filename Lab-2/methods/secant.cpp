#include "headers/secant.h"
#include "../headers/equations.h"

using namespace std;
using ld = long double;

void solve(ld a, ld b, int eq, ld eps=1e-3){
    vector<equation>f = get_equations();
    vector<equation>d2 = get_derivatives2();
    ld x0, x1;
    if(f[eq](a) * d2[eq](a) > 0) {
        x0 = a;
        x1 = a + 2*eps;
    }
    else{
        x0 = b;
        x1 = b - 2*eps;
    }
    while(abs(x1 - x0) > eps && abs(x1) > eps){
        ld x2 = x1 - (x1 - x0) / (f[eq](x1) - f[eq](x0)) * f[eq](x1);
        x0 = x1;
        x1 = x2;
    }
}

void secant(int eq){
    cout << "Метод секущих" << endl;
    pair<ld, ld>interval = choose_interval(eq);
    solve(interval.first, interval.second, eq);
}