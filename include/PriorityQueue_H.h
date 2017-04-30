#ifndef INCLUDE_PRIORITYQUEUE_H_H_
#define INCLUDE_PRIORITYQUEUE_H_H_
#include "Heap.h"
#include "RBTree.h"
#include <vector>
template < typename T >
class H_PriorityQueue : public SixHeap<T> {
 public:
};
template < typename T >
class RB_PriorityQueue : public RBTree<T> {
 public:
};
#endif  // INCLUDE_PRIORITYQUEUE_H_H_
