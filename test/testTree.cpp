#include <gtest/gtest.h>
#include "TreeSearch.h"

TEST(find, CanToFind) {
  CNode* root = new CNode(7);
  root->right = new CNode(10);
  root->right->right = new CNode(11);
  root->right->left = new CNode(9);
  root->left = new CNode(5);
  root->left->right = new CNode(6);
  root->left->left = new CNode(3);
  CNode* res = *find(&root, 6);

  EXPECT_EQ(res->val, 6);
}

TEST(find, CanToFind2) {
  CNode* root = new CNode(7);
  root->right = new CNode(10);
  root->right->right = new CNode(11);
  root->right->left = new CNode(9);
  root->left = new CNode(5);
  root->left->right = new CNode(6);
  root->left->left = new CNode(3);
  CNode* res = *find(&root, 9);

  EXPECT_EQ(res->val, 9);
}

TEST(find, ReturnCorrectAddresIfKeyMissingInTree1) {
  CNode* root = new CNode(7);
  root->right = new CNode(10);
  root->right->right = new CNode(11);
  root->right->left = new CNode(9);
  root->left = new CNode(5);
  root->left->right = new CNode(6);
  root->left->left = new CNode(3);
  CNode** res = find(&root, 1);
  CNode** r = &(root->left->left->left);

  EXPECT_EQ(r, res);
}

TEST(find, ReturnCorrectAddresIfKeyMissingInTree2) {
  CNode* root = new CNode(7);
  root->right = new CNode(10);
  root->right->right = new CNode(11);
  root->right->left = new CNode(9);
  root->left = new CNode(5);
  root->left->right = new CNode(6);
  root->left->left = new CNode(3);
  CNode** res = find(&root, 12);
  CNode** r = &(root->right->right->right);

  EXPECT_EQ(r, res);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
