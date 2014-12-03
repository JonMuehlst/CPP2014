/*
* Based on the code from the following link:
* http://www.cs.uregina.ca/Links/class-info/170/07-templates/
*/

#include <iostream>
#include <string>
#include "matrix.h"
#include "mergesort.h"
#include "main.h"
#include "gtest/gtest.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;



int main(int argc, char ** argv)
{

    Matrix<int> intMatrix = Matrix<int>();
    Matrix<int> A = Matrix<int>();
    setExampleIntMatrixA(A);
    
    Matrix<int> B = Matrix<int>();
    setExampleIntMatrixB(B);
    
    Matrix<string> stringMatrix = Matrix<string>();
    Matrix<string> As = Matrix<string>();
    setExampleStringMatrixA(As);
    
    Matrix<string> Bs = Matrix<string>();
    setExampleStringMatrixB(Bs);
    cout << "\nDemonstrating with string matrix:" << endl;
    demoTemplate(stringMatrix, As, Bs);

    cout << "\nDemonstrating with int matrix:" << endl;
    demoTemplate(intMatrix, A, B);


    cout << "\n" << endl;
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();              
}

