#include "headers/vector_io.h"

void print_separator(){
    cout << "___________________________________________________________" << endl;
}

void print_error(string s){
    cerr << s << endl;
    //exit(0);
}

void print_message(string s){
    cout << s << endl;
}

void read_matrix(int n, vector<vector<ld>>&matrix){
    print_message("Введите матрицу, состоящую ровно из " + to_string(n) + " строк и столбцов");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void print_matrix(int n, const vector<vector<ld>>&matrix){
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cout << setw(15) << setprecision(5) << fixed << matrix[row][col] << ' ';
        }
        cout << endl;
    }
}

void read_vector(int n, vector<ld>&vec){
    print_message("Введите ровно " + to_string(n) + " чисел: столбец свободных членов");
    for(auto &i : vec) cin >> i;
}

void print_vector(int n, vector<ld>&vec,  string desc=""){
    for(int i = 0; i < n; i++){
        cout << desc << i << " = " << setw(10) << setprecision(25) << fixed << vec[i] << endl;
    }
    cout << "\n";
}
