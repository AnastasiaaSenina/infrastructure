#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_
#include <stdlib.h>
#include <vector>
using std :: vector;

template < typename T >
class SixHeap {
 private:
<<<<<<< HEAD
 vector < T> mas;
=======
>>>>>>> 02919fa64299ec077e3042cba315a1d047f17df7
 void ShiftUP(int index);
 void ShiftDown();
 int MinSoon(int index_parent);
 public:
<<<<<<< HEAD
   T operator[](int index);

  void InsertEl(T a);
  void DeleteMin();
  T GetMin();
  int Size() {
    return mas.size();
  }
=======
  vector < T> mas;
  void InsertEl(T a);
  void DeleteMin();
  void DeleteEl(T a);
  T GetMin();
>>>>>>> 02919fa64299ec077e3042cba315a1d047f17df7
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
<<<<<<< HEAD
  int index_min_soon = MinSoon(0);
  while (index_min_soon >= 0 && index_min_soon <= mas.size() - 1 &&  mas[parent] > mas[index_min_soon]) {
=======
  //T current = mas[0];
  int index_min_soon = MinSoon(0);
  while (index_min_soon <= mas.size() - 1 &&  mas[parent] > mas[index_min_soon]) {
>>>>>>> 02919fa64299ec077e3042cba315a1d047f17df7
    tmp = mas[index_min_soon];
    mas[index_min_soon] = mas[parent];
    mas[parent] = tmp;
    parent = index_min_soon;
    index_min_soon = MinSoon(parent);
  }
}

template < typename T >
void SixHeap<T>::DeleteMin() {
<<<<<<< HEAD
    if (Size() != 0) {
      T tmp;
      tmp = mas[0];
      mas[0] = mas[mas.size() - 1];
      mas.pop_back();
      ShiftDown();
    } else {
      throw 1;
    }
=======
  if (mas.size() != 0) {
    T tmp;
    tmp = mas[0];
    mas[0] = mas[mas.size() - 1];
    mas.pop_back();
    ShiftDown();
  } else {
    throw 1;
  }
>>>>>>> 02919fa64299ec077e3042cba315a1d047f17df7
}

template < typename T> 
T SixHeap<T>::GetMin(){
<<<<<<< HEAD
  if (mas.size() != 0) {
    return mas[0];
  } else { 
    throw 1;
  }
}

template < typename T >
T SixHeap<T>::operator[](int index) {
  return mas[index];
}



=======
  return mas[0];
}

template < typename T >
void DeleteEl(T a) {
/////////////////////???????????????//////////////
}

>>>>>>> 02919fa64299ec077e3042cba315a1d047f17df7
#endif  // INCLUDE_HEAP_H_
