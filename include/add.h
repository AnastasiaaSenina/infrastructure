#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#include <vector>
#include <set>
#include <algorithm>
#define MAX 1000000
#include <tuple>
using std::vector;
using std::tuple;
using std::pair;
using std:: set;
using std:: get;


class Union_Find {
 private:
  int size;
  int* set;
  int* åmployment_set;

 public:
  void Union_set(int number_set1, int number_set2);
  int Find_set(int number_el);
  explicit  Union_Find(int s) {
    size = s;
    set = new int[s];
    åmployment_set = new int[s];
    for (unsigned int i = 0; i < size; ++i) {
      set[i] = i;
      åmployment_set[i] = 1;
    }
  }
  // äëÿ òåñòîâ
  int GetSize() {
    return size;
  }
  int GetSet(int i) {
    return set[i];
  }
  int GetEmp_Set(int i) {
    return åmployment_set[i];
  }
};

#endif  // INCLUDE_ADD_H_
