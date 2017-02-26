#include "TreeSearch.h"

CNode::CNode(int v) {
  val = v;
  right = 0;
  left = 0;
}
CNode** find(CNode** root, int v) {
  CNode** croot = root;
  while (*croot) {
    if ((*croot)->val == v) {
      return croot;
    } else {
      if ((*croot)->val > v) {
        croot = &((*croot)->left);
      } else {
        croot = &((*croot)->right);
      }
    }
  }
  return croot;
}
void print3(CNode **root) {
  std::queue <CNode**> q;
  q.push(root);
  while (!q.empty()) {
    CNode** root1 = q.front();
    std::cout << "zveno" << " " << root1 <<
    "   " << (*root1)->val  << std::endl;
    if ((*root1)->right) {
      q.push(&(*root1)->right);
    }
    if ((*root1)->left) {
      q.push(&(*root1)->left);
    }
    std::cout << "root->right" << " " << &(*root1)->right << " " << std::endl;
    std::cout << "root->left" << " " << &(*root1)->left << " " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    q.pop();
  }
}

