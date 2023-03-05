#ifndef COUNTING_MATH_EQUATIONS_H
#define COUNTING_MATH_EQUATIONS_H
#include "bits/stdc++.h"
using namespace std;
using ld = long double;
typedef ld (*equation)(ld x);
typedef ld (*equation2)(ld x, ld y);

vector<equation>get_equations();
vector<equation>get_derivatives();
vector<equation>get_derivatives2();
vector<pair<equation2, equation2>>get_systems();
vector<pair<equation2, equation2>>get_systems_dx();
vector<pair<equation2, equation2>>get_systems_dy();
bool check_root_exist(ld a, ld b, int eq);
bool check_only_root(ld a, ld b, int eq);
pair<ld, ld> choose_interval(int eq);

#endif //COUNTING_MATH_EQUATIONS_H
