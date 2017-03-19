#include "CreateTree.h"
#include <queue>

limit::limit(int l, int r) {
  left = l;
  right = r;
}
CNode* CreateBinTreeForMas(int masslen, int mass[]) {
  if (masslen == 0) {
    return nullptr;
  }
  std::queue <CNode*> nodes;
  std:: queue <limit*> lim;
  limit* pos = new limit(0, masslen-1);
  lim.push(pos);
  CNode *root1 = new CNode;
  nodes.push(root1);
  limit* index;

  while (!nodes.empty()) {
    CNode* s = nodes.front();
    nodes.pop();
    index = lim.front();
    lim.pop();
    if ((index->right - index->left) == 1) {
      s->right = new CNode;
      s->val = mass[index->left];
      nodes.push(s->right);
      limit* indexright = new limit(index->right, index->right);
      lim.push(indexright);
    } else {
      if ((index->right == index->left)) {
        s->val = mass[index->right];
      } else {
         s->left = new CNode;
         s->right = new CNode;
         int position = (index->left + index->right -
         ((index->left + index->right)%2))/2;
         s->val = mass[position];
         limit* indexleft = new limit(index->left, position - 1);
         lim.push(indexleft);
         nodes.push(s->left);
         limit* indexright = new limit(position + 1, index->right);
         lim.push(indexright);
         nodes.push(s->right);
        }
    }
  }
  return root1;
}
