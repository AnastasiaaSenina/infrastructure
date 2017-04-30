#include <gtest/gtest.h>
#include "Heap.h"

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

  for (unsigned int i = 0; i < res.size(); ++i)
  EXPECT_EQ(res[i], a[i]);
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

  for (unsigned int i = 0; i < res.size(); ++i)
    EXPECT_EQ(res[i], a[i]);
}



TEST(SixHeap, ThrowWhenGetMinInEmptyHeap) {
  SixHeap<int> a;
  ASSERT_ANY_THROW(a.GetMin());
}

TEST(SixHeap, CanGetCorrectMinElement) {
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

TEST(SixHeap, ThrowWhenDeleteMinElementInEmpty) {
  SixHeap<int> a;

  ASSERT_ANY_THROW(a.DeleteMin());
}

TEST(SixHeap, CanCorrectGetSize) {
  SixHeap< int> a;
  vector<int> res;

  a.InsertEl(10);
  a.InsertEl(13);
  a.InsertEl(9);
  a.InsertEl(8);
  a.InsertEl(11);
  a.InsertEl(12);
  a.InsertEl(4);
  a.InsertEl(7);

  EXPECT_EQ(8, a.Size());
}
