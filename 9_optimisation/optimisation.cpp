#include <iostream>
#include <vector>
#include <cassert> 
#include <cstdlib>
#include "gtest/gtest.h"

#include "optimisation.hpp"
#include "tictoc.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::swap;

//  Matrix Multiplication - Naive O(n^3)
// =================================================================================
void matrixMultiplication(int A[][N], int B[][N], int C[][N], size_t size){
    
    assert(size <= N);
    
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                C[k][i] += A[k][j] * B[j][i];
            }
        }
    }
    
}
// =================================================================================

// Quick Sort
// =================================================================================
void quickSort(int A[], int left, int right){
    
    int i = left;
    int j = right;
    int tmp = 0;
    int pivot = A[(left + right) / 2];
    
    while( i <= j ){
        
        while( A[i] < pivot )
            i++;
        while( A[j] > pivot )
            j--;
        
        if( i <= j){
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }
    
    if( left < j )
        quickSort(A,left,j);
    if( i < right )
        quickSort(A,i,right);
    
}
// =================================================================================

// Generic Quick Sort
// =================================================================================
template <typename T>
void quick_sort_template(T A[], int left, int right){
    
    int i = left;
    int j = right;
    T tmp = 0;
    T pivot = A[(left + right) / 2];
    
    while( i <= j ){
        
        while( A[i] < pivot )
            i++;
        while( A[j] > pivot )
            j--;
        
        if( i <= j){
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }
    
    if( left < j )
        quick_sort_template(A,left,j);
    if( i < right )
        quick_sort_template(A,i,right);
    
}
// =================================================================================

// Generate Fibonacci sequence by matrix multiplication
// =================================================================================
/*

(F(n+1) F(n)  ) (1 1) = ( F(n+1)+F(n)   F(n+1))
(F(n)   F(n-1)) (1 0) = ( F(n)+F(n-1)   F(n)  )

*/
unsigned long long int fibonacci_by_matrix(size_t num){

    vector<vector<unsigned long long int> > A{ {1, 1}, {1, 0}};
    vector<vector<unsigned long long int> > F{ {1, 1}, {1, 0}};
    
    F = exp_by_squaring(A,num+1);

    // cout << F[1][1] << endl;
    
    return F[1][1];
    
}

// Exponentiation by squaring
vector<vector<unsigned long long int> > exp_by_squaring(vector<vector<unsigned long long int> >& x, size_t n){
     
     if( n == 0 ){ 
         vector<vector<unsigned long long int> > identity{ {1, 0}, {0, 1} };
        return identity;
     } else if( n == 1 ){ 
         return x;
     } else if( n % 2 == 0 ){
         two_by_two_matrix_square(x);
         return exp_by_squaring( x, n/2);
     } else{
         vector<vector<unsigned long long int> > x_squared(x);
         two_by_two_matrix_square(x_squared);
         vector<vector<unsigned long long int> > B = exp_by_squaring(x_squared, (n-1)/2);
         two_by_two_matrix_multiplication(x, B);
         return x;
     }
}

// Helper functions.
inline void two_by_two_matrix_square(vector<vector<unsigned long long int> >& A){
        
        vector<vector<unsigned long long int> > TMP(2, vector<unsigned long long int>(2));
        
        TMP[0][0] = A[0][0]*A[0][0] + A[0][1]*A[1][0];
        TMP[0][1] = A[0][0]*A[0][1] + A[0][1]*A[1][1];
        TMP[1][0] = A[1][0]*A[0][0] + A[1][1]*A[1][0];
        TMP[1][1] = A[1][0]*A[0][1] + A[1][1]*A[1][1];
        
        A[0][0] = TMP[0][0];
        A[0][1] = TMP[0][1];
        A[1][0] = TMP[1][0];
        A[1][1] = TMP[1][1];
}

inline void two_by_two_matrix_multiplication(vector<vector<unsigned long long int> >& F, vector<vector<unsigned long long int> >& A){
        
        vector<vector<unsigned long long int> > TMP(2, vector<unsigned long long int>(2));
        
        TMP[0][0] = F[0][0]*A[0][0] + F[0][1]*A[1][0];
        TMP[0][1] = F[0][0]*A[0][1] + F[0][1]*A[1][1];
        TMP[1][0] = F[1][0]*A[0][0] + F[1][1]*A[1][0];
        TMP[1][1] = F[1][0]*A[0][1] + F[1][1]*A[1][1];
        
        F[0][0] = TMP[0][0];
        F[0][1] = TMP[0][1];
        F[1][0] = TMP[1][0];
        F[1][1] = TMP[1][1];
}
// =================================================================================




// Using Google test to measure computation time

/*================================================================================

                                    Tests

================================================================================*/

// TEST(Opt, matrix_multiplication){
    
//     srand((unsigned int) time(0));
    
//     int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
//     int C[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
//     int exptected_C[3][3] = {{30,24,18},{84,69,54},{138,114,90}};
    
//     // for (int i = 0; i < N; i++) {
//     //     for (int j = 0; j < N; j++) {
//     //             A[i][j] = (int)rand()*1000 + 1;
//     //             B[i][j] = (int)rand()*1000 + 1;
//     //             C[i][j] = (int)rand()*1000 + 1;
//     //     }
//     // }
    
//     matrixMultiplication(A,B,C,3);
    
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//                 EXPECT_EQ(exptected_C[i][j],C[i][j]);
//         }
//     }
// }

// TEST(Opt, matrix_multiplication_time){
    
//     srand((unsigned int) time(0));
    
//     int A[N][N];
//     int B[N][N];
//     int C[N][N];
    
//     size_t size = N;
    
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//                 A[i][j] = (int)rand()*1000 + 1;
//                 B[i][j] = (int)rand()*1000 + 1;
//                 C[i][j] = (int)rand()*1000 + 1;
//         }
//     }
    
//     matrixMultiplication(A,B,C,size);
    
// }

// TEST(Opt, quick_sort){
    
//     int A[M];
//     srand(time(0));
//     for (int i = 0; i < M; i++) {
//         A[i] = (int)rand()*1000000 + 1;
//     }
    
//     quickSort(A, 0, M);
   
//     // cout << "Done" << endl;
//     for(size_t i = 0; i < M - 1; i++){
//         EXPECT_LE(A[i], A[i+1]);   
//     }
    
// }

// TEST(Opt, quick_sort_template_int){
    
//     int A[M];
//     srand(time(0));
//     for (int i = 0; i < M; i++) {
//         A[i] = (int)rand()*1000000 + 1;
//     }
    
//     quick_sort_template(A, 0, M);
    
//     for(size_t i = 0; i < M - 1; i++){
//         EXPECT_LE(A[i], A[i+1]);   
//     }
    
// }

// TEST(Opt, quick_sort_template_double){
    
//     double D[M];
//     srand(time(0));
//     for (int i = 0; i < M; i++) {
//         D[i] = rand()*1000000 + 1;
//     }
    
//     quick_sort_template(D, 0, M);
    
//     for(size_t i = 0; i < M - 1; i++){
//         EXPECT_LE(D[i], D[i+1]);   
//     }
    
// }

TEST(Opt, fib){
    
    // fibonacci_by_matrix(100);
    
    EXPECT_EQ(3736710778780434371, fibonacci_by_matrix(100));
    
}