#include <gtest/gtest.h>
#include "add.h"
#include "Heap.h"

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(SixHeap, CanInseartElInHeap) {

  SixHeap< int> a;
  vector<int> res;

  res.push_back(4);
  res.push_back(7);
  res.push_back(10);
  res.push_back(9);
  res.push_back(11);
  res.push_back(12);
  res.push_back(8);
  res.push_back(13);

  a.InsertEl(10);
  a.InsertEl(13);
  a.InsertEl(9);
  a.InsertEl(8);
  a.InsertEl(11);
  a.InsertEl(12);
  a.InsertEl(4);
  a.InsertEl(7);

  EXPECT_EQ(res,a.mas);

}

TEST(SixHeap, CanDeleteMinEl) {

  SixHeap<int> a;
  vector<int> res;

  res.push_back(7);
  res.push_back(13);
  res.push_back(10);
  res.push_back(9);
  res.push_back(11);
  res.push_back(12);
  res.push_back(8);

  a.InsertEl(10);
  a.InsertEl(13);
  a.InsertEl(9);
  a.InsertEl(8);
  a.InsertEl(11);
  a.InsertEl(12);
  a.InsertEl(4);
  a.InsertEl(7);
  a.DeleteMin();

  EXPECT_EQ(res, a.mas);

}

TEST(SixHeap, CanGetCorrectMinElement){
 
  SixHeap<int> a;
  a.InsertEl(10);
  a.InsertEl(13);
  a.InsertEl(9);
  a.InsertEl(8);
  a.InsertEl(11);
  a.InsertEl(12);
  a.InsertEl(4);
  a.InsertEl(7);

  EXPECT_EQ(a.GetMin(), 4);

}

TEST(SixHeap, ThrowWhenDeleteMinElementInEmpty){

  SixHeap<int> a;

  ASSERT_ANY_THROW(a.DeleteMin());

}


