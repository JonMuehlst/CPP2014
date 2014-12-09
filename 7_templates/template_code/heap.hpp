#ifndef __HEAP_H__
#define __HEAP_H__

#include <assert.h>
#include "gtest/gtest.h"

template <typename T, int MAX_HEAP_ELEMS = 100>
class heap{
  
  private:
    /* Number of values currently in the heap. */
    int num_values;
    
    /* The values in the heap. */
    T values[MAX_HEAP_ELEMS];  
  
  public:
    heap(){
      num_values = 0;
    }
    
    heap(T * a, int a_size){
      num_values = 0;
      for(int i = 0; i < a_size; i++){
        add_value(a[i]);
      }
    }

    /* Given an index, the parent index is computed as follows.
     * The "index" value is supposed to be an integer.
     */
    inline size_t parent(size_t index){
      return (((index) - 1) / 2);
    }

    /*
     * For heaps stored in an array, left child and right child
     * of a particular index are calculated using these functions.
     * The "index" value is supposed to be an integer.
     */
    inline size_t  left_child_index(size_t index){ 
      return (2 * (index) + 1);
    }
    
    inline size_t right_child_index(size_t index){
     return (2 * (index) + 2);
    }

    /* Returns the first (i.e. smallest) value in the heap. */
    T get_first_value();
    
    /* Adds another value to the heap, in the proper place. */
    void add_value(T newval);

    
    /*
     * These are declarations of local functions that are used
     * internally by the heap data structure, but are not visible
     * outside this module.
     */
    
    void sift_down(int index);
    void sift_up(int index);
    void swap_values(int i, int j);

    int size();
    int get_max_size();
    
    FRIEND_TEST(heap_test_class, heapified);
};

/* Returns the first (i.e. smallest) value in the heap. */
template <typename T, int MAX_HEAP_ELEMS>
T heap<T,MAX_HEAP_ELEMS>::get_first_value()
{
  float result;

  /* There needs to be at least one value left in the heap! */
  assert(num_values > 0);

  /* Smallest value is at the root - index 0. */
  result = values[0];

  /* Decrease the count of how many values are in the heap.
   * NOTE that if there was more than one value in the heap,
   * the last value is still at values[num_values], so we have
   * to move it to the new vacancy that opened up at the root.
   * If there was only one value in the heap when "get-first"
   * was called, we're done.
   */
  num_values--;
  if (num_values != 0)
  {
    /* Move the last value in the heap to the root. */
    values[0] = values[num_values];

    /* Sift down the new value to position it properly
     * in the heap.
     */
    sift_down(0);
  }

  return result;
}


/* Adds another value to the heap, in the proper place. */
template <typename T, int MAX_HEAP_ELEMS>
void heap<T,MAX_HEAP_ELEMS>::add_value(T newval)
{
  int index;
  
  assert(num_values >= 0);

  /* There needs to be room for one more element in the heap... */
  assert(num_values < MAX_HEAP_ELEMS);

  /* Add the new value to the end of the heap, then sift up. */

  index = num_values;
  values[index] = newval;
  num_values++;

  /* If the new value isn't at the root, sift up. */
  if (index != 0)
    sift_up(index);
}


/*==================*/
/* HELPER FUNCTIONS */
/*==================*/


/*
 * Given a heap and an index, sift_down checks to see if the value
 * at that index needs to be "sifted downward" in the heap, to
 * preserve the heap properties.  Specifically, a value needs to
 * be moved down in the heap if it is greater than either of its
 * children's values.  (This is the "order" property.)  In order
 * to preserve the "shape" property of heaps, the value is swapped
 * with the *smaller* of its two child values.
 *
 * If a value only has a left child, then only the left child is
 * examined for the swap.
 *
 * If a value has both left and right children, it is possible
 * that one child may be larger than the value, while the other is
 * smaller than the value.  Since we swap with the smallest child
 * value, we preserve the heap properties even in that situation.
 */
template <typename T, int MAX_HEAP_ELEMS>
void heap<T,MAX_HEAP_ELEMS>::sift_down(int index)
{
  assert(num_values > 0);
  assert(index < num_values);

  int left_child = left_child_index(index);
  int right_child = right_child_index(index);

  if (left_child >= num_values)
  {
    /* If the left child's index is past the end of the heap
     * then this value has no children.  We're done.
     */
    return;
  }

  if (right_child >= num_values)
  {
    /* Only have a left child. */

    if (values[left_child] < values[index])
    {
      /* Left child value is smaller.  Swap this value and the
       * left child value.
       */
      swap_values(index, left_child);

      /* Don't need to call sift_down again, because if this
       * node only has a left child, we are at the bottom of
       * the heap.
       */
    }
  }
  else
  {
    /* This value has a left and right child. */

    float left_val = values[left_child];
    float right_val = values[right_child];
    int swap_child;

    if (left_val < values[index] ||
        right_val < values[index])
    {
      /* Need to swap this node with one of its children.  Pick
       * the smaller of the two children, since this is a min-heap
       * and that will preserve the heap properties.
       */
      if (left_val < right_val)
        swap_child = left_child;
      else
        swap_child = right_child;

      /* Do the swap, then call sift_down again, in case we aren't
       * at the bottom of the heap yet.
       */
      swap_values(index, swap_child);
      sift_down(swap_child);
    }
  }
}


/*
 * Given a heap and an index, sift_up checks to see if the value
 * at that index needs to be "sifted upward" in the heap, to
 * preserve the heap properties.  Specifically, a value needs to
 * be moved up in the heap if it is less than its parent value.
 * (This is just the "order" property; the "shape" property is
 * not affected by sifting a value up.)
 */
template <typename T, int MAX_HEAP_ELEMS>
void heap<T,MAX_HEAP_ELEMS>::sift_up(int index)
{
  int parent_index = parent(index);

  /* If the index to sift up is the root, we are done. */
  if (index == 0)
    return;

  assert(parent_index >= 0);
  assert(parent_index != index);  /* Parent of index 0 = 0... that's bad. */

  /* If the specified value is smaller than its parent value then
   * we have to swap the value and its parent.
   */
  if (values[index] < values[parent_index])
  {
    /* Swap the value with its parent value. */
    swap_values(index, parent_index);

    /* If we haven't gotten to the root, we might have to
     * sift up again.
     */
    if (parent_index != 0)
      sift_up(parent_index);
  }
}


/*
 * Helper function to handle the onerous task of swapping two
 * values in the value array of a heap.
 */
template <typename T, int MAX_HEAP_ELEMS>
void heap<T,MAX_HEAP_ELEMS>::swap_values(int i, int j)
{
  float tmp;

  assert(num_values > 0);
  assert(i >= 0 && i < num_values);
  assert(j >= 0 && j < num_values);
  assert(i != j);

  tmp = values[i];
  values[i] = values[j];
  values[j] = tmp;
}

template <typename T, int MAX_HEAP_ELEMS>
int heap<T,MAX_HEAP_ELEMS>::size(){
  return num_values;
}

template <typename T, int MAX_HEAP_ELEMS>
int heap<T,MAX_HEAP_ELEMS>::get_max_size(){
  return MAX_HEAP_ELEMS;
}

#endif /* __HEAP_H__ */
