#include "headers/equations.h"

/*
 * Уравнения
 */
static ld e1(ld x){
    return x*x*x - 2*x;
}

static ld e2(ld x){
    return sin(x) + 2*cos(x);
}
/*
 * Системы уравнений
 */
static ld sys1_1(ld x, ld y){
    return x*x + y*y - 4;
}

static ld sys1_2(ld x, ld y){
    return -3*x*x + y;
}
/*
 * Частичные производные систем по x
 */
static ld sys1_1_dx(ld x, ld y){
    return 2*x;
}
static ld sys1_2_dx(ld x, ld y){
    return -6*x;
}

/*
 * Частичные производные систем по y
 */

static ld sys1_1_dy(ld x, ld y){
    return 2*y;
}

static ld sys1_2_dy(ld x, ld y){
    return 1;
}

/*
 * 1-e производные уравнений
 */
static ld e1_d(ld x){
    return 3*x*x - 2;
}

static ld e2_d(ld x){
    return cos(x) - 2*sin(x);
}

/*
 * 2-е производные
 */
static ld e1_d2(ld x){
    return 6*x;
}

static ld e2_d2(ld x){
    return -sin(x) - 2*cos(x);
}

const int SIZE = 2;
const vector<equation>equations = {&e1, &e2};
const vector<equation>derivatives = {&e1_d, &e2_d};
const vector<equation>derivatives2 = {&e1_d2, &e2_d2};
const vector<pair<equation2, equation2>>systems = {
        {&sys1_1, &sys1_2}
};
const vector<pair<equation2, equation2>>systems_dx = {
        {&sys1_1_dx, &sys1_2_dx}
};
const vector<pair<equation2, equation2>>systems_dy = {
        {&sys1_1_dy, &sys1_2_dy}
};

vector<equation>get_equations(){
    return equations;
}
vector<equation>get_derivatives(){
    return derivatives;
}

vector<equation>get_derivatives2(){
    return derivatives2;
}

vector<pair<equation2, equation2>>get_systems(){
    return systems;
}

vector<pair<equation2, equation2>>get_systems_dx(){
    return systems_dx;
}

vector<pair<equation2, equation2>>get_systems_dy(){
    return systems_dy;
}

bool check_root_exist(ld a, ld b, int eq){
    vector<equation>f = get_equations();
    return f[eq](a) * f[eq](b) < 0;
}

bool check_only_root(ld a, ld b, int eq){
    vector<equation>f = get_derivatives();
    bool was_zero = false, was_minus = false, was_plus = false;
    int cnt = 0;
    for(ld x = a; x <= b; x +=1e-4){
        if(f[eq](x) > 0) was_plus = true;
        if(f[eq](x) == 0) was_zero = true;
        if(f[eq](x) < 0) was_minus = true;
        cnt++;
        //if(cnt % 100 == 0) cout << f[eq](x) << endl;
    }
    if(was_minus && was_plus) return false;
    else return true;
    //TODO
}

pair<ld, ld> choose_interval(int eq){
    ld a, b;
    cout << "Введите интервал для поиска корня" << endl;
    cin >> a >> b;
    if(!check_root_exist(a, b, eq)){
        cout << "На данном промежутке нет корней!" << endl;
        exit(0);
    }

    if(!check_only_root(a, b, eq)){
        cout << "На данном промежутке более 1 корня!" << endl;
        exit(0);
    }
    return {a, b};
}

