#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__

#include "heap.hpp"

template <typename T>
void heapSort(T * a, int a_size){
  heap<T> h = heap<T>(a,a_size);
  
  for(int i = 0; i < a_size; i++)
    a[i] = h.get_first_value();
}

#endif /* __HEAP_SORT_H__ */
