#ifndef INCLUDE_PRIORITYQUEUE_H_H_
#define INCLUDE_PRIORITYQUEUE_H_H_
#include "Heap.h"
#include "RBTree.h"
#include <vector>
template < typename T >
class H_PriorityQueue : public SixHeap<T> {
 public:
   H_PriorityQueue(){}
  ~H_PriorityQueue(){}
   T FindMin() {
     return GetMin();
   }
   bool isempty() {
     if (Size() == 0)
       return true;
     else
       return false;
   }
};
template < typename T >
class RB_PriorityQueue : public RBTree<T> {
  public:
    RB_PriorityQueue(){};
    ~RB_PriorityQueue(){};
    T Getmin() {
      return GetMin();
    }
    bool Isempty() {
      return isempty();
    }
};
#endif  // INCLUDE_PRIORITYQUEUE_H_H_
