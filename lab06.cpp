/*
Program: EECS 348 Lab 06
Function: Read an input file two square matrices, and have functions to print a matrix, add two matrices, multiply two matrices, subtract M2 from M1, update an element on a matrix, get the max value in a matrix, and transpose a matrix
Author: Aiden Burke
Date Modified: 03/10/2024
*/

#include <iostream>
#include <fstream> // include fstream for file I/O

using std::cout;
using std::cin;
using std::ifstream;
using std::string;

const int max_size = 10;

void read_matrix(int m1[max_size][max_size], int m2[max_size][max_size], int& size, const string& name){
    ifstream file(name);
    file >> size;
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            file >> m1[i][j];
        }
    }
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            file >> m2[i][j];
        }
    }
    file.close();
};

void print_matrix(int matrix[max_size][max_size], int size){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            cout << matrix[i][j] << "\t";
        };
        cout << "\n";
    }
    cout << "\n";
};
void add_matrix(int m1[max_size][max_size], int m2[max_size][max_size], int result[max_size][max_size], int size){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
};
void multiply_matrix(int m1[max_size][max_size], int m2[max_size][max_size], int result[max_size][max_size], int size){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            result[i][j] = 0;
        }
    }
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            for(int k=0; k < size; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
};
void subtract_matrix(int m1[max_size][max_size], int m2[max_size][max_size], int result[max_size][max_size], int size){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
};
void update_matrix(int matrix[max_size][max_size], int size){
    while(1){
    int row, col, n;
    cout << "Row of matrix 1 you want to update? (Assume row counting begins at 0): ";
    cin >> row;
    cout << "Column of matrix 1 you want to update? (Assume column counting begins at 0): ";
    cin >> col;
    cout << "What value do you want to put in row " << row << ", column " << col << " of matrix 1?: ";
    cin >> n;
    if(row < size & col < size){
        matrix[row][col] = n;
        break;
    } else {
        cout << "Invalid row/column.\n";
    }
    }
};
void get_max(int matrix[max_size][max_size], int size){
    int max = matrix[0][0];
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }
    cout << "Max value of matrix 1: " << max << "\n\n";
};
void transpose(int matrix[max_size][max_size], int result[max_size][max_size], int size){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            result[j][i] = matrix[i][j];
        }
    }
};

int main() {
    int matrix1[max_size][max_size];
    int matrix2[max_size][max_size];
    int size;

    read_matrix(matrix1, matrix2, size, "matrix_input.txt");
    // read size, matrix 1, and matrix 2 from file

    cout << "Matrix 1:\n";
    print_matrix(matrix1, size);
    cout << "Matrix 2:\n";
    print_matrix(matrix2, size);

    int addition_result[max_size][max_size];
    add_matrix(matrix1, matrix2, addition_result, size);
    cout << "Matrix 1 + Matrix 2:\n";
    print_matrix(addition_result, size);

    int multiplication_result[max_size][max_size];
    multiply_matrix(matrix1, matrix2, multiplication_result, size);
    cout << "Matrix 1 * Matrix 2:\n";
    print_matrix(multiplication_result, size);

    int subtraction_result[max_size][max_size];
    subtract_matrix(matrix1, matrix2, subtraction_result, size);
    cout << "Matrix 1 - Matrix 2:\n";
    print_matrix(subtraction_result, size);

    update_matrix(matrix1, size);
    cout << "Updated matrix 1:\n";
    print_matrix(matrix1, size);

    get_max(matrix1, size);

    int transpose_result[max_size][max_size];
    transpose(matrix1, transpose_result, size);
    cout << "Transposed (and updated) Matrix 1:\n";
    print_matrix(transpose_result, size);

    return 0;
};
