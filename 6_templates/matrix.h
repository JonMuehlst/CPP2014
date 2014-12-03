/*
* Based on the code from the following link:
* http://www.cs.uregina.ca/Links/class-info/170/07-templates/
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cassert>
#include "matrix.h"
#include "mergesort.h"
#include "gtest/gtest.h"


template <typename Type>
class Matrix
{
    private:
    Type ** mat;
    int dim;
    
    public:
    
    // Init function
    void init(int);
    //------------------------------
    
    // Ctors
    Matrix(int _dim = 3){ init(_dim); }
    Matrix(Type **,int);
    Matrix(const Matrix&);
    //------------------------------
    
    // Dtor
    ~Matrix();
    //------------------------------
    
    // Utility functions
    void printMatrix();
    //------------------------------
    
    // Getters
    const int getDimension() const;
    //------------------------------
    
    // Unary operators
    Matrix<Type>& operator=(const Matrix<Type> & rhs);
    //------------------------------
    
    // friend binary operators
    template <typename T>
    friend const Matrix<T> operator+(const Matrix<T> & lhs, const Matrix<T> & rhs);
    //------------------------------
    
    // friend Demo functions
    template <typename T>
    friend void setExampleIntMatrixA(Matrix<T>& M);
    
    template <typename T>
    friend void setExampleIntMatrixB(Matrix<T>& M);
    
    template <typename T>
    friend void setExampleStringMatrixA(Matrix<T>& M);
    
    template <typename T>
    friend void setExampleStringMatrixB(Matrix<T>& M);
    //------------------------------
    
    // Friend tests
    FRIEND_TEST(matrix_test_class, assignment);
    FRIEND_TEST(matrix_test_class, addition);
    //------------------------------
};

// Class implementation


using std::cout;
using std::endl;
using std::cin;
template<typename Type>
void Matrix<Type>::init(int _dim){
  
  dim = _dim;
  
  mat = new Type * [dim];
  
  for (int i=0; i< dim; i++){
      mat[i] = new Type[dim];
  }
  
  for (int i=0; i< dim; i++){
      for(int j=0; j< dim; j++){
         mat[i][j] = '\0';
      }
  }
}

template<typename Type>
Matrix<Type>::Matrix(Type ** a, int _dim){
   
   init(_dim);

   for (int i=0; i< dim; i++)
   {
      for(int j=0; j< dim; j++)
      {
	      mat[i][j] = a[i][j];
      }
   }   
   
}

template<typename Type>
Matrix<Type>::Matrix(const Matrix<Type>& m){
   
  init(m.getDimension());
   
   for (int i=0; i< dim; i++)
   {
      for(int j=0; j< dim; j++)
      {
	      mat[i][j] = m.mat[i][j];
      }
   }   
   
}

template<typename Type>
Matrix<Type>::~Matrix(){
   
   for (int i=0; i< dim; i++){
      delete [] mat[i];
   }
   
   delete [] mat;
}

template<typename Type>
void Matrix<Type>::printMatrix()
{
   
   for (int i=0; i< dim; i++)
   {
      for(int j=0; j< dim; j++)
      {
   	   cout << mat[i][j] << "\t";
      }
      cout << endl;
   }
}

template<typename T>
const Matrix<T> operator+(const Matrix<T> & lhs, const Matrix<T> & rhs){
   
   assert(lhs.getDimension() == rhs.getDimension());
   
   int _dim = lhs.getDimension();
   
   Matrix<T> m = Matrix<T>(_dim);
   
   for (int i=0; i< _dim; i++)
   {
      for(int j=0; j< _dim; j++)
      {
	      m.mat[i][j] = lhs.mat[i][j] + rhs.mat[i][j];
      }
   }
   
   return m;
   
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator=(const Matrix<Type> & rhs){
   
   assert(dim == rhs.getDimension());
   
   for (int i=0; i< dim; i++)
   {
      for(int j=0; j< dim; j++)
      {
	      this->mat[i][j] = rhs.mat[i][j];
      }
   }
   
   return *this;
   
}

template<typename Type>
const int Matrix<Type>::getDimension() const {
   
   return dim;
   
}

template<typename T>
void setExampleIntMatrixA(Matrix<T>& M){
    
   assert(M.dim == 3);
   
   M.mat[0][0] = 1;
   M.mat[0][1] = 2;
   M.mat[0][2] = 3;
   M.mat[1][0] = 4;
   M.mat[1][1] = 5;
   M.mat[1][2] = 6;
   M.mat[2][0] = 7;
   M.mat[2][1] = 8;
   M.mat[2][2] = 9;

}

template<typename T>
void setExampleIntMatrixB(Matrix<T>& M){

   assert(M.dim == 3);

   M.mat[0][0] = 9;
   M.mat[0][1] = 8;
   M.mat[0][2] = 7;   
   M.mat[1][0] = 6;
   M.mat[1][1] = 5;
   M.mat[1][2] = 4;
   M.mat[2][0] = 3;
   M.mat[2][1] = 2;
   M.mat[2][2] = 1;

}

template<typename T>
void setExampleStringMatrixA(Matrix<T>& M){
   
   assert(M.dim == 3);
   
   M.mat[0][0] = "Congra";
   M.mat[0][1] = "y";
   M.mat[0][2] = "ar";
   M.mat[1][0] = "alm";
   M.mat[1][1] = "don";
   M.mat[1][2] = "La";

}

template<typename T>
void setExampleStringMatrixB(Matrix<T>& M){

   assert(M.dim == 3);
   
   M.mat[0][0] = "tulations";
   M.mat[0][1] = "ou";
   M.mat[0][2] = "e";
   M.mat[1][0] = "ost";
   M.mat[1][1] = "e    the";
   M.mat[1][2] = "b!";

}

#endif