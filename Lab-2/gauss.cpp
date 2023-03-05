#include "headers/gauss.h"
int inverses = 0;

enum result{
    NO_SOL = 0,
    ENDLESS_SOL = 1,
    ONE_SOL = 2
};

/*
 * Перестановка строк
 */
static void swap_rows(int row, vector<vector<ld>>&matrix, vector<ld>&b){
    int cur = row, n = len(matrix);
    while (cur < n && matrix[cur][row] == 0) cur++;
    if(cur == n) return;
    else {
        swap(matrix[row], matrix[cur]);
        swap(b[row], b[cur]);
        inverses++;
    }
}

/*
 * Приведение матрицы к треугольному виду
 */
static void make_triangle(int n, vector<vector<ld>>&matrix, vector<ld>&b){
    for(int i = 0; i < n; i++){
        if(matrix[i][i] == 0) swap_rows(i, matrix, b);
        if(matrix[i][i] == 0) break;
        for(int k = i + 1; k < n; k++){
            ld c = matrix[k][i] / matrix[i][i];
            matrix[k][i] = 0;
            for(int j = i + 1; j < n; j++){
                matrix[k][j] -= c * matrix[i][j];
            }
            b[k] = b[k] - c * b[i];
        }
    }
}

/*
 * Вычисление вектора неизвестных х
 */
static vector<ld> count_x(int n, vector<vector<ld>>&matrix, vector<ld>&b){
    vector<ld>x(n);
    for(int i = n - 1; i >= 0; i--){
        ld s = 0;
        for(int j = i + 1; j < n; j++){
            s += matrix[i][j] * x[j];
        }
        x[i] = (b[i] - s) / matrix[i][i];
        if(x[i] == -0) x[i] = 0;
    }
    return x;
}

/*
 * Вычисление определителя
 */
static ld count_determinant(int n, vector<vector<ld>>&matrix){
    ld determinant = 1l;
    for(int i = 0; i < n; i++)  determinant *= matrix[i][i];
    return determinant * (inverses % 2 == 0 ? 1 : -1);
}
/*
 * Вычисление вектора невязок
 */
static vector<ld> count_discrepancy(int n, vector<vector<ld>>&matrix, vector<ld>&b, vector<ld>&x){
    vector<ld>discrepancy(n, 0);
    for(int i = 0; i < n; i++){
        ld a_x = 0;
        for(int j = 0; j < n; j++){
            a_x += matrix[i][j] * x[j];
        }
        discrepancy[i] = a_x - b[i];
    }
    return discrepancy;
}

/*
 * Определение количества решений системы на основании ранга
 */
int check_rang(int n, vector<vector<ld>>&matrix, vector<ld>&b){
    int zero_sum = n, zero_sum_b = n;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) sum++;
        }
        if(sum == n) zero_sum--;
        if(sum == n && b[i] == 0) zero_sum_b--;
    }
    if(zero_sum != zero_sum_b) return NO_SOL;
    else if(zero_sum == zero_sum_b && zero_sum < n) return ENDLESS_SOL;
    else return ONE_SOL;
}
/*
 * Вычисление СЛАУ методом Гаусса и вывод результатов
 */
vector<ld> gauss(int n, vector<vector<ld>>&matrix, vector<ld>&b){
    make_triangle(n, matrix, b);
    int solution = check_rang(n, matrix, b);
    if(solution == NO_SOL) {
        print_message("No solution");
        exit(0);
    }
    else if(solution == ENDLESS_SOL){
        print_message("Endless number of solutions");
        exit(0);
    }
    return count_x(n, matrix, b);
}
