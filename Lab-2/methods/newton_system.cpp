#include "headers/newton_system.h"
const int SIZE = 2;

void solve(ld x0, ld y0, int sys){
    vector<pair<equation2, equation2>>systems = get_systems();
    vector<pair<equation2, equation2>>system_dx = get_systems_dx();
    vector<pair<equation2, equation2>>system_dy = get_systems_dy();
    cout << system_dx[sys].first(x0, y0) << endl;
    vector<vector<ld>>matrix = {
            {system_dx[sys].first(x0, y0), system_dy[sys].first(x0, y0)},
            {system_dx[sys].second(x0, y0), system_dy[sys].second(x0, y0)}
    };
    vector<ld>b = {
            -systems[sys].first(x0, y0), -systems[sys].second(x0, y0)
    };
    print_matrix(SIZE, matrix);
    print_vector(SIZE, b, "b");

}

void newton_system(int sys){
    cout << "Введите начальное приближение" << endl;
    ld x0, y0;
    cin >> x0 >> y0;
    solve(x0, y0, sys);
}
