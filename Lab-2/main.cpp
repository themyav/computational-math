#include "bits/stdc++.h"
#include "headers/vector_io.h"
#include "methods/headers/binary_division.h"
#include "methods/headers/secant.h"


using namespace std;


void choose_equation_method(int eq){
    print_message("Выберите метод для решения нелинейного уравнения");
    print_message("1 - метод половинного деления");
    print_message("2 - метод секущих");
    print_message("3 - метод простой итерации");
    //TODO
    string num;
    cin >> num;
    if(num == "1") binary_division(eq);
    else if(num == "2") secant(eq);
}

void solve_system(){
    print_message("Выберите метод для решения систем нелинейных уравнений");

}

void solve_equation(){
    print_message("Введите номер уравнения, которое вы хотите решить");
    ifstream fin("/home/kristina/CLionProjects/counting-math/Lab-2/equations");
    string s;
    int cnt = 0;
    while (getline(fin, s)) {
        cout << "№" << cnt << ": " << s << endl;
        cnt++;
    }
    fin.close();
    //TODO
    string num;
    cin >> num;
    choose_equation_method(stoi(num));
}

void choose_option(){
    print_message("Введите номер интересующей вас опции");
    print_message("1 - решить нелинейное уравнение");
    print_message("2 - решить систему нелинейных уравнений");
    print_message("3 - выход");
    string s;
    while (s.empty()){
        getline(cin, s);
        if(s == "1") solve_equation();
        else if(s == "2") solve_system();
        else if(s == "3") {
            print_message("Завершение работы программы!");
            exit(0);
        }
        else{
            print_error("Введите номер одной из предложенных опций!");
            s = "";
        }
    }
}

int main(){
    freopen("/home/kristina/CLionProjects/counting-math/Lab-2/input.txt", "r", stdin);
    choose_option();
    return 0;
}