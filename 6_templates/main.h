/*
* Based on the code from the following link:
* http://www.cs.uregina.ca/Links/class-info/170/07-templates/
*/

#ifndef MAIN_H_
#define MAIN_H_

template <typename Type>
void demoTemplate(Matrix<Type>&, Matrix<Type>&, Matrix<Type>&);

// Implementation

template <typename Type>
void demoTemplate(Matrix<Type>& M, Matrix<Type>& A, Matrix<Type>& B)
{
    
    M = A;
    cout << "\nMatrix set to the first matrix parameter" << endl;
    M.printMatrix();
    
    cout << "\nThe second Matrix parameter is:" << endl;
    B.printMatrix();
    
    M = M + B;
    
    cout << "\nMatrix incremented by second array" << endl; 
    M.printMatrix();
}

#endif