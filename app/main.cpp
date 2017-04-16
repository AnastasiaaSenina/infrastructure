#include <iostream>
#include "add.h"
#include "Heap.h"

int main() {
  SixHeap< int> a;
  a.InsertEl(10);
  a.InsertEl(13);
  a.InsertEl(9);
  a.InsertEl(8);
  a.InsertEl(11);
  a.InsertEl(12);
  a.InsertEl(4);
  a.InsertEl(7);
  a.DeleteMin();
}