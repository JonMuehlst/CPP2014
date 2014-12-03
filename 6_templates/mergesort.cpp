/*
 * C++ implementation of Merge Sort 
 * Based on the code from the following link:
 * http://www.sanfoundry.com/cpp-program-implement-merge-sort/
 */
 
// Implementation is in the header file
// See following explanation 
// http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
 
#include "mergesort.h"

/*================================================================================

                                    Tests

================================================================================*/

TEST(Mergesort, the_sort){
    
    int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    double d[] = { 10.11, 9.22, 8.33, 7.44, 6.55, 5.66, 4.77, 3.88, 2.99, 1.78 };
    
    mergesort(a, 0, 9);
    mergesort(d, 0, 9);
    
    for(size_t i = 0; i < 10 - 1; i++){
        EXPECT_LE(a[i], a[i+1]);   
        EXPECT_LE(d[i], a[i+1]);   
    }
    
}