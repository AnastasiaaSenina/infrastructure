#include <gtest/gtest.h>
#include "RBTRee.h"
using std:: pair;
using std:: vector;

/*
TEST(RBTree, CanInseartInEmptyTree) {
  RBTree <int> a;
  int v = 2;
  a.Insert(v);
  EXPECT_TRUE(a.root->color == 0);
  EXPECT_TRUE(a.root->left == NIL);
  EXPECT_TRUE(a.root->right == NIL);
  EXPECT_TRUE(a.root->parent == NIL);
  EXPECT_TRUE(a.root->value == v);
}

TEST(RBTree, CanInseartInNOTEmptyTree) {
  RBTree <int> a;
  a.Insert(2);
  a.Insert(3);

  EXPECT_TRUE(a.root->color == 0);
  EXPECT_TRUE(a.root->left->color == 0);
  EXPECT_TRUE(a.root->left->value == 0);
  EXPECT_TRUE(a.root->left == NIL);
  EXPECT_TRUE(a.root->right != NIL);

  EXPECT_TRUE(a.root->right->color == 1);
  EXPECT_TRUE(a.root->right->value == 3);

  EXPECT_TRUE(a.root->right->left == NIL);
  EXPECT_TRUE(a.root->right->right == NIL);
  EXPECT_TRUE(a.root->value == 2);
  EXPECT_TRUE(a.root->right->parent == a.root);
}

TEST(RBTree, ThrowFindWhenTreeIsEmpty) {
  RBTree < int > a;

  ASSERT_ANY_THROW(a.Find(7));
}

TEST(RBTree, CanFindCorrectForValueInTree) {
  rbnode<int>* res;
  RBTree<int> a;
  a.Insert(2);
  a.Insert(3);
  a.Insert(4);
  res = a.Find(3);
  EXPECT_EQ(res, a.root);
}

TEST(RBTree, CanDeleteForValueInTree) {
  rbnode<int>* res;
  RBTree<int> a;
  a.Insert(2);
  a.Insert(3);
  a.Insert(4);
  a.Delete(4);
  res = a.Find(4);

  EXPECT_TRUE(res == nullptr );
}

TEST(RBTree, CanDeleteForAdressInTree) {
  rbnode<int>* res = nullptr;
  RBTree<int> a;
  a.Insert(2);
  a.Insert(3);
  a.Insert(4);
  //a.Delete(4);
   a.Delete(a.Find(3));
   res = a.Find(3);   
   EXPECT_TRUE(res == nullptr);
   EXPECT_EQ(a.root->value, 4);
   EXPECT_EQ(a.root->color, 0);
   EXPECT_EQ(a.root->parent, NIL);
   EXPECT_EQ(a.root->left->value, 2);
   EXPECT_EQ(a.root->left->color, 1);

   EXPECT_EQ(a.root->left->right, NIL);
   EXPECT_EQ(a.root->left->left, NIL);
   EXPECT_EQ(a.root->value, 4);
   EXPECT_EQ(a.root->right, NIL);
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





