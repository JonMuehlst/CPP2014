#ifndef OPTIMISATION_HPP
#define OPTIMISATION_HPP

#define N 500
#define M 10000000

void matrixMultiplication(int A[N][N], int B[N][N], int C[N][N], size_t size);

void quickSort(int A[], int left, int right);

template <typename T>
void quick_sort_template(T A[], int left, int right);

unsigned long long int fibonacci_by_matrix(size_t num);
void two_by_two_matrix_multiplication(unsigned long long int F[2][2], unsigned long long int A[2][2]);

#endif