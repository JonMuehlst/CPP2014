#include <stdlib.h>
#include "gtest/gtest.h"
#include "binary_search_tree.hpp"

/*================================================================================

                                    Tests

================================================================================*/

class bst_test_class : public ::testing::Test {
    
    public:
        BinarySearchTree<double> bst;
        BinarySearchTree<double> bst_c;
        double a[100];
  
        virtual void SetUp(){
            
            /* Use a seed so that the sequence of random values
             * is always the same.
             */
            srand(time(0));
            
            /* Fill up the heap with random values. */
            for (int i = 0; i < 10; i++){
              a[i] = rand() % 1000;
              bst.insert(a[i]);
            }
            
            // bst_c = BinarySearchTree<double>(a,10);
            
        }
    
};

// TEST_F(bst_test_class, bst_sort){
  
//   bstSort(a,100);
  
//   for(size_t i = 0; i < 100 - 1; i++){
//       EXPECT_LE(a[i], a[i+1]);   
//   }
// }

TEST_F(bst_test_class, print_bst){
    
        BinarySearchTree<double> bst2;
  
        for (int i = 0; i < 10; i = i + 2){
          EXPECT_TRUE(bst2.insert(i));
        }
        
        for (int i = -10; i < 0; i = i + 2){
          EXPECT_TRUE(bst2.insert(i));
        }
        
        for (int i = -9; i < 10; i = i + 2){
          EXPECT_TRUE(bst2.insert(i));
        }
        
    
    bst2.inOrderWalk();
    bst2.preOrderWalk();
    bst2.postOrderWalk();
  
}
