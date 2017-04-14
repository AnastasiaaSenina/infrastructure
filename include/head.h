#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_
#include <stdlib.h>
#include <vector>
using std::vector;
template < typename T >
class SixHeap {
private:
  vector < T> mas;
  void ShiftUP(int index);
  void ShiftDown();
  int MinSoon(int index_parent);
public:
  void InsertEl(T a);
  void DeleteMin();
  void DeleteEl();
  void GetMin();

};

template < typename T >
void InsertEl(T a) {
  vector[mas.size()] = a;
  ShiftUP(mas.size());
}

template < typename T>
void ShiftUP(int index) {
  T tmp;
  while (mas[index] < mas[(index - 1) / 6]) {
    tmp = mas[index];
    mas[index] = mas[(index - 1) / 6];
    mas[(index - 1) / 6] = tmp;
    index = (index - 1) / 6;
  }
}
template <typename T>
int MinSoon(int index_parent) {
  T minsoon = min(mas[6 * index_parent + 1], mas[6 * index_parent + 2],
    mas[6 * index_parent + 3], mas[6 * index_parent + 4],
    mas[6 * index_parent + 5], mas[6 * index_parent + 6], );
  if (mas[6 * index_parent + 1] == minsoon)
    return 6 * index_parent + 1;
  if (mas[6 * index_parent + 2] == minsoon)
    return 6 * index_parent + 2;
  if (mas[6 * index_parent + 3] == minsoon)
    return 6 * index_parent + 3;
  if (mas[6 * index_parent + 4] == minsoon)
    return 6 * index_parent + 4;
  if (mas[6 * index_parent + 5] == minsoon)
    return 6 * index_parent + 5;
  if (mas[6 * index_parent + 6] == minsoon)
    return 6 * index_parent + 6;
}

template < typename T>
void SHiftDown() {

}
template < typename T >
void DeleteMin() {/// добавь проверкy, если куча пуста!
  T tmp;
  tmp = mas[0];
  mas[0] = mas[mas.size() - 1];
  mas[mas.size() - 1] = tmp;
  ShiftDown();
}
#endif  // INCLUDE_HEAP_H_
