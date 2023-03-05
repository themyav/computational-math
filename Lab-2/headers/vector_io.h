#ifndef COUNTING_MATH_VECTOR_IO_H
#define COUNTING_MATH_VECTOR_IO_H
#include <bits/stdc++.h>
using namespace std;
using ld = long double;

void print_error(string s);
void print_message(string s);
void read_matrix(int n, vector<vector<ld>>&matrix);
void print_matrix(int n, const vector<vector<ld>>&matrix);
void read_vector(int n, vector<ld>&vec);
void print_vector(int n, vector<ld>&vec, string desc);
void print_separator();


#endif //COUNTING_MATH_VECTOR_IO_H
