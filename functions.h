#include <stdio.h>
#include<string.h>

void tern_string_text_in_matrix(char* text, int mat[][2], int rows, int cols);
void print_matrix(int m, int n, int mat[][2]);
void multiplay_any_2_matrix(int mat1[][2], int mat2[][2], int m1, int n1, int m2, int n2, int res[][2]);
void matrix_scalar_mul(int mat[][2], int scalar, int res[][2], int rows, int cols);
void add_matrixes(int mat1[][2], int mat2[][2], int res[][2], int rows, int cols);
void applay_modolo(int a[][2], int num, int rows, int cols);
char* door_encryption(char* ptext, char* key);
int modulo(int num);
void calc_invertible_matrix(int mat[][2], int rows, int cols, float res[][2]);
char* door_decryption(char*ctext, char*key);
int inverse_number(int num);