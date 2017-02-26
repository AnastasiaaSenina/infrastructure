#ifndef INCLUDE_TREESEARCH_H_
#define INCLUDE_TREESEARCH_H_
#include <iostream>
#include <queue>

struct CNode {
  int val;
  CNode *left, *right;
  explicit CNode(int v);
};
CNode** find(CNode** root, int v);
void print3(CNode** root);
#endif  // INCLUDE_TREESEARCH_H_
