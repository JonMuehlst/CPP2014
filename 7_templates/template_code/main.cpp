#include <stdlib.h>

#include "heap.hpp"
#include "heap_sort.hpp"
#include "gtest/gtest.h"

int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*================================================================================

                                    Tests

================================================================================*/

class heap_test_class : public ::testing::Test {
    
    public:
        heap<double,100> h;
        double a[100];
  
        virtual void SetUp(){
            
            /* Use a seed so that the sequence of random values
             * is always the same.
             */
            srand(time(0));
            
            /* Fill up the heap with random values. */
            for (int i = 0; i < 100; i++){
              a[i] = rand() % 1000;
            }
            
            h = heap<double,100>(a,100);
            
        }
    
};

TEST_F(heap_test_class, heap_sort){
  
  heapSort(a,100);
  
  for(size_t i = 0; i < 100 - 1; i++){
      EXPECT_LE(a[i], a[i+1]);   
  }
}

TEST_F(heap_test_class, heapified){
  
  heap<double,100> h = heap<double,100>(a,100);
  
  for(size_t i = h.size() - 1; i > 0; i--){
      EXPECT_LE(h.values[h.parent(i)], h.values[i]);   
  }
}
