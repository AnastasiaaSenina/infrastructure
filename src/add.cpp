#include "add.h"

int Union_Find::Find_set(int number_el) {
  return set[number_el];
}
void Union_Find::Union_set(int number_set1, int number_set2) {
  if (employment_set[number_set1] >= employment_set[number_set2]) {
    for (int i = 0; i < size; ++i) {
      if (set[i] == number_set2)
        set[i] = number_set1;
     }
  }
}



