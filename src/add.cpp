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

int* func(int n, int k,vector< std::pair<int,int>> el ) {
  Union_Find a(n);
  for (int i = 0; i < n -1; ++i) {
    a.Union_set(i,i+1);
  }
  for (int i = 0; i < el.size(); i++) {
    if (a.Find_set(el[i].first) == a.Find_set(el[i].second)) {
      for (int j = 0; j < a.GetSize(); ++j) {
        if (j != a.Find_set(el[i].second) {
          a.Union_set(j, a.Find_set(el[i].second));
        }
      }
    }
  }

}


