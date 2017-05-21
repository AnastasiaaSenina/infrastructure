#include "add.h"
#include <stdexcept>

int Union_Find::Find_set(int number_el) {
  return set[number_el];
}
void Union_Find::Union_set(int number_set1, int number_set2) {
  if (employment_set[number_set1] >= employment_set[number_set2]) {
    for (int i = 0; i < size; ++i) {
      if (set[i] == number_set2) {
        set[i] = number_set1;
        employment_set[number_set1]++;
      }
    }
  } else {
    for (int i = 0; i < size; ++i) {
      if (set[i] == number_set1) {
        set[i] = number_set2;
        employment_set[number_set2]++;
      }
    }
  }
}

vector<int> func(int n, vector< std::pair<int, int>> v) {
  if (n == 0)
    throw std::logic_error("size can't be = 0");
  Union_Find T(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a = T.Find_set(i);
      int b = T.Find_set(j);
      bool flag = true;
      for (unsigned int k = 0; k < v.size(); k++) {
        if (((T.Find_set(v[k].first) == a) &&
          (T.Find_set(v[k].second) == b))
          || ((T.Find_set(v[k].first) == b) &&
          (T.Find_set(v[k].second) == a))) {
          flag = false;
          break;
        }
      }
      if (flag)
        T.Union_set(a, b);
    }
  }
  vector< int > res;
  for (int i = 0; i < n; i++)
    res.push_back(T.Find_set(i));
  return res;
}


