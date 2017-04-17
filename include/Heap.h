#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_
#include <stdlib.h>
#include <vector>
using std :: vector;

template < typename T >
class SixHeap {
 private:
 void ShiftUP(int index);
 void ShiftDown();
 int MinSoon(int index_parent);
 public:
  vector < T> mas;
  void InsertEl(T a);
  void DeleteMin();
  void DeleteEl(T a);
  T GetMin();
};

template < typename T >
void SixHeap<T>::InsertEl(T a) {
  mas.push_back(a);
  ShiftUP(mas.size() - 1);
}

template < typename T >
void SixHeap<T>::ShiftUP(int index) {
  T tmp;
  while (mas[index] < mas[(index - 1) / 6]) {
    tmp = mas[index];
    mas[index] = mas[(index-1)/6];
    mas[(index-1)/6] = tmp;
    index = (index-1)/6;
  }
}
template <typename T>
int SixHeap<T>::MinSoon(int index_parent) {
  int i;
  int index;

  if (6 * index_parent + 1 < mas.size())
    i = 6 * index_parent + 1;
  else
    return -1;
    index = i;
    
  while (i + 1 < mas.size()&& i <= 6*index_parent + 6){
    if (mas[index] > mas[i+1])
     index = i+1;
     i++;
  }
  return index;
}

template < typename T>
void SixHeap<T>::ShiftDown() {
  T tmp;
  int parent = 0;
  //T current = mas[0];
  int index_min_soon = MinSoon(0);
  while (index_min_soon <= mas.size() - 1 &&  mas[parent] > mas[index_min_soon]) {
    tmp = mas[index_min_soon];
    mas[index_min_soon] = mas[parent];
    mas[parent] = tmp;
    parent = index_min_soon;
    index_min_soon = MinSoon(parent);
  }
}

template < typename T >
void SixHeap<T>::DeleteMin() {
  if (mas.size() != 0) {
    T tmp;
    tmp = mas[0];
    mas[0] = mas[mas.size() - 1];
    mas.pop_back();
    ShiftDown();
  } else {
    throw 1;
  }
}

template < typename T> 
T SixHeap<T>::GetMin(){
  return mas[0];
}

template < typename T >
void DeleteEl(T a) {
/////////////////////???????????????//////////////
}

#endif  // INCLUDE_HEAP_H_
