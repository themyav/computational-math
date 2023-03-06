#include "bits/stdc++.h"
#include "headers/vector_io.h"
#include "methods/headers/binary_division.h"
#include "methods/headers/secant.h"
#include "methods/headers/simple_iteration.h"
#include "methods/headers/newton_system.h"
#include <Python.h>


using namespace std;

ofstream fout("/home/kristina/CLionProjects/counting-math/Lab-2/resource/data");


void choose_equation_method(int eq){
    print_message("Выберите метод для решения нелинейного уравнения");
    print_message("1 - метод половинного деления");
    print_message("2 - метод секущих");
    print_message("3 - метод простой итерации");
    //TODO
    string num;
    cin >> num;
    print_separator();
    if(num == "1") binary_division(eq);
    else if(num == "2") secant(eq);
    else if(num == "3") simple_iteration(eq);
}

void choose_system_method(int sys){
    print_message("Выберите метод для решения систем нелинейных уравнений");
    print_message("1 - метод Ньютона");
    //TODO
    string num;
    cin >> num;
    print_separator();
    if(num == "1") newton_system(sys);
}

void solve_system(){
    print_message("Введите номер системы, которую вы хотите решить");
    ifstream fin("/home/kristina/CLionProjects/counting-math/Lab-2/resource/systems");
    string s;
    int cnt = 1;
    while (getline(fin, s)) {
        if(s == "{") {
            cout << "№" << cnt << ": " << endl;
            cnt++;
        }
        cout << s << endl;
    }
    fin.close();
    //TODO
    string num;
    cin >> num;
    int pid = fork();

    if (!pid)
    {
        string command =  "python /home/kristina/CLionProjects/counting-math/Lab-2/drawer.py 2 " + num + " -5 5 &";
        system(command.c_str());
    }
    if(pid) choose_system_method(stoi(num) - 1);


}

void solve_equation(){
    print_message("Введите номер уравнения, которое вы хотите решить");
    ifstream fin("/home/kristina/CLionProjects/counting-math/Lab-2/resource/equations");
    string s;
    int cnt = 1;
    while (getline(fin, s)) {
        cout << "№" << cnt << ": " << s << endl;
        cnt++;
    }
    fin.close();
    //TODO
    string num;
    cin >> num;
    int pid = fork();
    if(!pid){
        string command =  "python /home/kristina/CLionProjects/counting-math/Lab-2/drawer.py 1 " + num + " -5 5";
        system(command.c_str());
    }
    if(pid) choose_equation_method(stoi(num) - 1);
}

void choose_option(){
    print_message("Введите номер интересующей вас опции");
    print_message("1 - решить нелинейное уравнение");
    print_message("2 - решить систему нелинейных уравнений");
    print_message("3 - выход");
    string s;
    while (s.empty()){
        getline(cin, s);
        if(s == "1") {
            fout << 1 << endl;
            solve_equation();
        }
        else if(s == "2") {
            fout << 2 << endl;
            solve_system();
        }
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


int main(int argc, char **argv){
    //system("python /home/kristina/CLionProjects/counting-math/Lab-2/drawer.py 1 1 -5 5");
    /*Py_Initialize();
    PyObject* sysPath = PySys_GetObject("path");
    PyList_Append(sysPath, PyUnicode_FromString("."));
    PyRun_SimpleString("exec(open(\"/home/kristina/CLionProjects/counting-math/Lab-2/drawer.py\").read())");*/
    // PyRun_SimpleString("import pandas as pd");
    //PyRun_SimpleString("import matplotlib.pyplot as plt\nplt.plot([1, 2, 3, 4])\nplt.ylabel('some numbers')\nplt.savefig('plot.png')\n");
    //Py_Finalize();
    /*Py_Initialize();
    PyRun_SimpleString("exec(open(\"/home/kristina/CLionProjects/counting-math/Lab-2/drawer.py\").read())");
    Py_Finalize();*/

    print_message("Хотите считать данные с файла?");
    print_message("1 - да, чтение с файла input.txt");
    print_message("2 - нет, чтение с консоли");
    string code;
    getline(cin, code);
    if(code == "1") freopen("/home/kristina/CLionProjects/counting-math/Lab-2/resource/input.txt", "r", stdin);
     choose_option();
    return 0;
}