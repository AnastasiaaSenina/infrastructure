#ifndef INCLUDE_PRIORITYQUEUE_RBTREE_H_
#define INCLUDE_PRIORITYQUEUE_RBTREE_H_
#include "Heap.h"

template < typename T > 
class H_PriorityQueue : public SixHeap<T> {
 public:
   H_PriorityQueue(){}
   ~H_PriorityQueue(){}
   T FindMin();
   bool isempty() {
     if ( mas.size() == 0 )
       return true;
     else
       return false;
   }
};
template < typename T >
T H_PriorityQueue<T>::FindMin() {
  return GetMin();
}

#endif  // INCLUDE_PRIORITYQUEUE_RBTREE_H_
