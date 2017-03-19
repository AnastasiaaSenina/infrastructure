#include <gtest/gtest.h>
#include "CreateTree.h"

TEST(CreateBinTree, CanCreatTreeForNotEmptyMassiv) {
  int mass[] = { 1, 2, 3, 4, 5 };
  CNode* root = CreateBinTreeForMas(5, mass);

  EXPECT_EQ(root->val, 3);
  EXPECT_EQ(root->right->val, 4);
  EXPECT_EQ(root->left->val, 1);
  EXPECT_EQ(root->right->right->val, 5);
  EXPECT_EQ(root->left->right->val, 2);
}

TEST(CreateBinTree, CanCreatTreeForNotEmptyMassiv1) {
  int mass[] = { 1, 2, 3, 4 };
  CNode* root = CreateBinTreeForMas(5, mass);

  EXPECT_EQ(root->val, 3);
  EXPECT_EQ(root->right->val, 4);
  EXPECT_EQ(root->left->val, 1);
  EXPECT_EQ(root->left->right->val, 2);
}

TEST(CreateBinTree, NoCanCreatTreeForEmptyMassiv) {
  CNode* root = CreateBinTreeForMas(0, nullptr);

  EXPECT_EQ(root, nullptr);
}
