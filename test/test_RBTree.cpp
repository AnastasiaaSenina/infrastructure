#include <gtest/gtest.h>
#include "RBTRee.h"
using std:: pair;
using std:: vector;

TEST(RBTree, CanInseartInEmptyTree) {
  RBTree <int> a;
  int v = 2;
  a.Insert(v);
  EXPECT_TRUE(a.root->color == 0);
  EXPECT_TRUE(a.root->left == reinterpret_cast<rbnode<int>*>(NIL));
  EXPECT_TRUE(a.root->right == reinterpret_cast<rbnode<int>*>(NIL));
  EXPECT_TRUE(a.root->parent == NULL);
  EXPECT_TRUE(a.root->value == v);
}

TEST(RBTree, CanInseartInNOTEmptyTree) {
  RBTree <int> a;
  a.Insert(2);
  a.Insert(3);

  EXPECT_TRUE(a.root->color == 0);
  EXPECT_TRUE(a.root->left == reinterpret_cast<rbnode<int>*>(NIL));
  EXPECT_TRUE(a.root->right != reinterpret_cast<rbnode<int>*>(NIL));

  EXPECT_TRUE(a.root->right->color == 1);
  EXPECT_TRUE(a.root->right->value == 3);

  EXPECT_TRUE(a.root->right->left == reinterpret_cast<rbnode<int>*>(NIL));
  EXPECT_TRUE(a.root->right->right == reinterpret_cast<rbnode<int>*>(NIL));
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

 //   bool res1 = a.CHECKCORRECT();
 //    EXPECT_EQ(res1, true);
}

TEST(RBTree, CanDeleteForValueInTree) {
  rbnode<int>* res;
  RBTree<int> a;
  a.Insert(2);
  a.Insert(3);
  a.Insert(4);
  a.Insert(10);
  a.Insert(5);
  a.Insert(23);
  a.Insert(0);
  a.Insert(11);
  a.Delete(4);
  res = a.Find(4);

  EXPECT_EQ(res, nullptr );

//  bool res1 = a.CHECKCORRECT();
 // EXPECT_EQ(res1, true);
}

TEST(RBTree, ThrowWhenDeleteInEmptyTree) {
  RBTree<int> a;

  ASSERT_ANY_THROW(a.Delete(6));
}

TEST(RBTree, CanDeleteForAdressInTree) {
  rbnode<int>* res = nullptr;
  RBTree<int> a;
  a.Insert(2);
  a.Insert(3);
  a.Insert(4);
   a.Delete(a.Find(3));
   res = a.Find(3);
   EXPECT_EQ(res, nullptr);
   EXPECT_EQ(a.root->value, 4);
   EXPECT_EQ(a.root->color, 0);
   EXPECT_TRUE(a.root->parent == NULL);
   EXPECT_EQ(a.root->left->value, 2);
   EXPECT_EQ(a.root->left->color, 1);

   EXPECT_TRUE(a.root->left->right == reinterpret_cast<rbnode<int>*>(NIL));
   EXPECT_TRUE(a.root->left->left == reinterpret_cast<rbnode<int>*>(NIL));
   EXPECT_EQ(a.root->value, 4);
   EXPECT_TRUE(a.root->right == reinterpret_cast<rbnode<int>*>(NIL));

  // bool res1 = a.CHECKCORRECT();
  // EXPECT_EQ(res1, true);

}

TEST(RBTree, CanCorrectDeleteMin) {
  rbnode<int>* res;
  RBTree<int> a;
  a.Insert(2);
  a.Insert(3);
  a.Insert(4);
  a.Insert(9);
  a.Insert(8);
  a.Insert(1);
  a.Insert(16);
  a.Insert(5);
  a.DeleteMin();

  res = a.Find(1);

  EXPECT_EQ(res, nullptr);

// bool res = a.CHECKCORRECT();
 // EXPECT_EQ(res, true);
}


