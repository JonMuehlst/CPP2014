/*
* Based on the code from the following link:
* http://www.cs.uregina.ca/Links/class-info/170/07-templates/
*/

// Implementation is in the header file
// See following explanation 
// http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

#include "matrix.h"

/*================================================================================

                                    Tests

================================================================================*/

class matrix_test_class : public ::testing::Test {
    
    public:
        Matrix<int> A, B, C;
    
        virtual void SetUp(){
            A = Matrix<int>();
            B = Matrix<int>();
            C = Matrix<int>();
            setExampleIntMatrixA(A);
            setExampleIntMatrixB(B);
        }
    
};

TEST_F(matrix_test_class, assignment){

A = B;

for(int i = 0; i < C.getDimension(); i++)
   for(int j = 0; j < C.getDimension(); j++)
      EXPECT_DOUBLE_EQ(B.mat[i][j], A.mat[i][j]);
      
}

TEST_F(matrix_test_class, addition){

C = A + B;

for(int i = 0; i < C.getDimension(); i++)
   for(int j = 0; j < C.getDimension(); j++)
      EXPECT_DOUBLE_EQ(10, C.mat[i][j]);
      
}