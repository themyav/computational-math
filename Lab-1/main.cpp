#include <bits/stdc++.h>
#include "vector_io.h"
#include "gauss.h"
using namespace std;
using ld = long double;


void choose_input(){
    print_message("Добро пожаловать в решатель систем уравнений методом ГАУССА.");
    string type;
    while (type.empty()){
        print_message("Выберите тип ввода. Введите 1, чтобы считать данные с файла, и 2, чтобы считать с консоли.");
        getline(cin, type);
        if(type == "1") {

            print_message("Выбран ввод с файла");
            string filename;
            ifstream fin;
            bool file_opend = false;

            while(!file_opend){
                print_message("Введите имя файла либо <<NUL>>, чтобы вернуться к выбору ТИПА ввода.");
                getline(cin, filename);
                fin.open(filename.c_str());
                if(filename == "NUL"){
                    type = "";
                    break;
                }
                if(fin.is_open()){
                    file_opend = true;
                }
                else print_error("Некорректное имя файла!");
            }
            if(file_opend) freopen(filename.c_str(), "r", stdin);
        }
        else if(type == "2"){
            print_message("Выбран ввод с консоли");
        }
        else{
            print_message("Вы ввели некорректное значение!");
            type = "";
        }
    }
}

void read_n(int &n){
    while(!(n >= 1 && n <= 20)){
        print_message("Введите целое число n от 1 до 20: количество строк в матрице");
        string s;
        getline(cin, s);
        try{
            n = stoi(s);
        }catch(std::invalid_argument const& ex){
            print_error("Значение n должно быть числом!");
            continue;
        }
        if(n < 1) print_error("Значение n должно быть не меньше 1!");
        else if(n > 20) print_error("Значение n должно быть не больше 20!");
    }
}

void read_data(int &n, vector<vector<ld>>&matrix, vector<ld>&b){
    choose_input();
    read_n(n);
    matrix = vector<vector<ld>>(n, vector<ld>(n, 0));
    b = vector<ld>(n, 0);

    read_matrix(n, matrix);
    print_message("Вы ввели матрицу:");
    print_matrix(n, matrix);
    read_vector(n, b);
    print_message("Вы ввели столбец свободных членов:");
    print_vector(n, b, "b");
}

int main() {

    int n = 0;
    vector<vector<ld>>matrix;
    vector<ld>b;

    read_data(n, matrix, b);
    print_message("\nРЕЗУЛЬТАТЫ:\n");
    gauss(n, matrix, b);

    return 0;
}
