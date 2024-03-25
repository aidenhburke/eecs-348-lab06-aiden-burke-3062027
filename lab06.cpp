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

// file I/O: fstream package
// ofstream :output
// ifstream: input
// open() opens a file with given mode (input, output, etc)
// close() closes the file
// read() reads data from a file
// write() writes data into a file
/*
Example:
fstream file;
file.open("example.txt", ios::in);
char data[100];
file.read(data, sizeof(data));
file.close();
*/

const int size = 3; // need to modify when reading file

void print_matrix(int matrix[size][size]){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            cout << matrix[i][j] << "\t";
        };
        cout << "\n";
    }
    cout << "\n";
};
void add_matrix(int m1[size][size], int m2[size][size], int result[size][size]){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
};
void multiply_matrix(int m1[size][size], int m2[size][size], int result[size][size]){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            for(int k=0; k < size; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
};
void subtract_matrix(int m1[size][size], int m2[size][size], int result[size][size]){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
};
void update_matrix(int matrix[size][size]){
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
void get_max(int matrix[size][size]){
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
void transpose(int matrix[size][size], int result[size][size]){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            result[j][i] = matrix[i][j];
        }
    }
};

int main() {

    int matrix1[size][size] = {{1,2,3},{4,5,6},{7,8,9}}; // make these read from file
    int matrix2[size][size] = {{2,3,4},{5,6,7},{8,9,10}}; // make these read from file

    // read size, matrix 1, and matrix 2 from file

    cout << "Matrix 1:\n";
    print_matrix(matrix1);
    cout << "Matrix 2:\n";
    print_matrix(matrix2);

    int addition_result[size][size];
    add_matrix(matrix1, matrix2, addition_result);
    cout << "Matrix 1 + Matrix 2:\n";
    print_matrix(addition_result);

    int multiplication_result[size][size];
    multiply_matrix(matrix1, matrix2, multiplication_result);
    cout << "Matrix 1 * Matrix 2:\n";
    print_matrix(multiplication_result);

    int subtraction_result[size][size];
    subtract_matrix(matrix1, matrix2, subtraction_result);
    cout << "Matrix 1 - Matrix 2:\n";
    print_matrix(subtraction_result);

    update_matrix(matrix1);
    cout << "Updated matrix 1:\n";
    print_matrix(matrix1);

    get_max(matrix1);

    int transpose_result[size][size];
    transpose(matrix1, transpose_result);
    cout << "Transposed Matrix 1:\n";
    print_matrix(transpose_result);

    return 0;
};
