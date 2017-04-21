#ifndef INCLUDE_CREATETREE_H_
#define INCLUDE_CREATETREE_H_
struct CNode {
  int val;
  CNode* left;
  CNode* right;
};
struct limit {
  int right;
  int left;
  explicit limit(int l, int r);
};
CNode** find(CNode** root, int v);
CNode* CreateBinTreeForMas(int masslen, int mass[]);

#endif  // INCLUDE_CREATETREE_H_
