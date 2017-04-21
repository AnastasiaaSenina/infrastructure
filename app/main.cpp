#include "TreeSearch.h"

int main() {
CNode* root = new CNode(7);  // формирование дерева
root->right = new CNode(10);
root->right-> right = new CNode(11);
root->right->left = new CNode(9);
root->left = new CNode(5);
root->left->right = new CNode(6);
root->left->left = new CNode(3);
std::cout << &root->left->left->left << std::endl;

CNode** res = find(&root, 10);
std::cout << "find(root,10)   " << res << std::endl << std::endl;
res = find(&root, 6);
std::cout << "find(root,6)   " << res << std::endl << std::endl;
res = find(&root, 11);
std::cout << "find(root,11)   " << res << std::endl << std::endl;
res = find(&root, 3);
std::cout << "find(root,3)   " << res << std::endl << std::endl;
res = find(&root, 1);
std::cout << "find(root,1)   " << res << std::endl << std::endl;
// печать дерева
print3(&root);
*res = new CNode(1);
print3(&root);
}

