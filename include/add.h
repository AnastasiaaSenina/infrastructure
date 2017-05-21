#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#include <vector>
using std :: vector;

struct index {
  int str;  // stroka
  int stlb;  // stolbec
};
int Find(std::vector<int> a, int v);
void Union(vector<int> *a, vector<int> *b, int el1, int el2);
vector<vector<int>> IslandUF(vector<vector<int>> mas);
vector<vector<int>> IslandWidth(vector<vector<int>>
  mas);
#endif  // INCLUDE_ADD_H_
