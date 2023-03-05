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
 * 1-e производные
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

vector<equation>get_equations(){
    return equations;
}
vector<equation>get_derivatives(){
    return derivatives;
}

vector<equation>get_derivatives2(){
    return derivatives2;
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

