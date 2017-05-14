#include <gtest/gtest.h>
#include "add.h"
#include "alg_krask.h"
#include "alg_Prima.h"

TEST(Union_Find, CanCreateSetWithSize) {
  Union_Find a(5);
  EXPECT_EQ(a.GetSize(), 5);
  for (int i = 0; i < 5; ++i) {
    EXPECT_TRUE(a.GetSet(i) == i);
    EXPECT_TRUE(a.GetEmp_Set(i) == 1);
  }
}

TEST(Union_Find, CanFindSet) {
  Union_Find a(5);
  EXPECT_TRUE(a.Find_set(1) == 1);
}

TEST(Union_Find, CanUnionSet) {
  Union_Find a(5);
  a.Union_set(1, 2);
  EXPECT_EQ(a.Find_set(2), a.Find_set(1));
  EXPECT_EQ(a.Find_set(2), 1);
}

TEST(alg_krask, CorrectFindOstov) {
  vector<vector<int>> graph;
  vector< int > edg1;
  edg1.push_back(0);
  edg1.push_back(3);
  edg1.push_back(2);
  edg1.push_back(1);
  edg1.push_back(0);

  graph.push_back(edg1);

  vector< int > edg2;
  edg2.push_back(0);
  edg2.push_back(8);
  edg2.push_back(0);
  edg2.push_back(0);

  graph.push_back(edg2);

  vector< int > edg3;
  edg3.push_back(0);
  edg3.push_back(5);
  edg3.push_back(4);

  graph.push_back(edg3);

  vector< int > edg4;
  edg4.push_back(0);
  edg4.push_back(0);

  graph.push_back(edg4);

  vector< int > edg5;
  edg5.push_back(0);

  graph.push_back(edg5);

  vector <vector <int> > ostov = alg_krask(graph);
  vector<int> edg6;
  edg6.push_back(0);
  edg6.push_back(0);
  edg6.push_back(0);
  edg6.push_back(0);

  vector <int> edg7;
  edg7.push_back(0);
  edg7.push_back(0);
  edg7.push_back(4);

  EXPECT_EQ(ostov[0], edg1);
  EXPECT_EQ(ostov[1], edg6);
  EXPECT_EQ(ostov[2], edg7);
  EXPECT_EQ(ostov[3], edg4);
  EXPECT_EQ(ostov[4], edg5);
}

TEST(alg_krask, CorrectFindOstov1) {
  vector<vector<int>> graph;
  vector< int > edg1;
  edg1.push_back(0);
  edg1.push_back(3);
  edg1.push_back(2);
  edg1.push_back(1);
  edg1.push_back(1);

  graph.push_back(edg1);

  vector< int > edg2;
  edg2.push_back(0);
  edg2.push_back(8);
  edg2.push_back(2);
  edg2.push_back(2);

  graph.push_back(edg2);

  vector< int > edg3;
  edg3.push_back(0);
  edg3.push_back(5);
  edg3.push_back(4);

  graph.push_back(edg3);

  vector< int > edg4;
  edg4.push_back(0);
  edg4.push_back(1);

  graph.push_back(edg4);

  vector< int > edg5;
  edg5.push_back(0);

  graph.push_back(edg5);

  vector <vector <int> > ostov = alg_krask(graph);
  vector<int> edg6;
  edg6.push_back(0);
  edg6.push_back(0);
  edg6.push_back(2);
  edg6.push_back(1);
  edg6.push_back(1);

  vector <int> edg7;
  edg7.push_back(0);
  edg7.push_back(0);
  edg7.push_back(2);
  edg7.push_back(0);

  vector <int> edg8;
  edg8.push_back(0);
  edg8.push_back(0);
  edg8.push_back(0);

  vector <int> edg9;
  edg9.push_back(0);
  edg9.push_back(0);

  vector <int> edg10;
  edg10.push_back(0);

  EXPECT_EQ(ostov[0], edg6);
  EXPECT_EQ(ostov[1], edg7);
  EXPECT_EQ(ostov[2], edg8);
  EXPECT_EQ(ostov[3], edg9);
  EXPECT_EQ(ostov[4], edg10);
}

TEST(alg_krask, ThrowsWhenGraphisEmpty) {
  vector<vector<int>> a;
  ASSERT_ANY_THROW(alg_krask(a));
}

TEST(alg_Prima, ThrowsWhenGraphisEmpty) {
  vector<vector<int>> a;
  ASSERT_ANY_THROW(alg_Prima(a));
}

TEST(alg_Prima, CanFindOstov) {
  vector<vector<int>> graph;
  vector< int > edg1;
  edg1.push_back(1);
  edg1.push_back(0);
  edg1.push_back(1);
  edg1.push_back(0);
  edg1.push_back(1);

  graph.push_back(edg1);

  vector< int > edg2;
  edg2.push_back(1);
  edg2.push_back(0);
  edg2.push_back(0);
  edg2.push_back(1);
  edg2.push_back(1);

  graph.push_back(edg2);

  vector< int > edg3;
  edg3.push_back(2);
  edg3.push_back(1);
  edg3.push_back(0);
  edg3.push_back(1);
  edg3.push_back(0);

  graph.push_back(edg3);

  vector< int > edg4;
  edg4.push_back(4);
  edg4.push_back(0);
  edg4.push_back(1);
  edg4.push_back(1);
  edg4.push_back(0);

  graph.push_back(edg4);

  vector< int > edg5;
  edg5.push_back(5);
  edg5.push_back(1);
  edg5.push_back(0);
  edg5.push_back(0);
  edg5.push_back(1);

  graph.push_back(edg5);

  vector< int > edg6;
  edg6.push_back(3);
  edg6.push_back(1);
  edg6.push_back(1);
  edg6.push_back(0);
  edg6.push_back(0);

  graph.push_back(edg6);

  vector <vector <int> > ostov = alg_Prima(graph);

  EXPECT_EQ(ostov[0], edg1);
  EXPECT_EQ(ostov[1], edg2);
  EXPECT_EQ(ostov[2], edg3);
}

TEST(Alg_Prima, CanFindOstov1) {
  vector <vector<int> > graph;

  vector<int> edg0;
  edg0.push_back(1);
  edg0.push_back(1);
  edg0.push_back(1);
  edg0.push_back(0);
  edg0.push_back(0);
  edg0.push_back(0);
  edg0.push_back(0);

  vector<int> edg1;
  edg1.push_back(5);
  edg1.push_back(0);
  edg1.push_back(1);
  edg1.push_back(1);
  edg1.push_back(0);
  edg1.push_back(0);
  edg1.push_back(0);

  vector<int> edg2;
  edg2.push_back(3);
  edg2.push_back(0);
  edg2.push_back(0);
  edg2.push_back(1);
  edg2.push_back(1);
  edg2.push_back(0);
  edg2.push_back(0);

  vector<int> edg3;
  edg3.push_back(4);
  edg3.push_back(0);
  edg3.push_back(0);
  edg3.push_back(0);
  edg3.push_back(1);
  edg3.push_back(1);
  edg3.push_back(0);

  vector<int> edg4;
  edg4.push_back(10);
  edg4.push_back(1);
  edg4.push_back(0);
  edg4.push_back(0);
  edg4.push_back(0);
  edg4.push_back(1);
  edg4.push_back(0);

  vector<int> edg5;
  edg5.push_back(8);
  edg5.push_back(0);
  edg5.push_back(0);
  edg5.push_back(1);
  edg5.push_back(0);
  edg5.push_back(0);
  edg5.push_back(1);

  vector<int> edg6;
  edg6.push_back(7);
  edg6.push_back(0);
  edg6.push_back(0);
  edg6.push_back(0);
  edg6.push_back(0);
  edg6.push_back(1);
  edg6.push_back(1);

  graph.push_back(edg0);
  graph.push_back(edg1);
  graph.push_back(edg2);
  graph.push_back(edg3);
  graph.push_back(edg4);
  graph.push_back(edg5);
  graph.push_back(edg6);

  vector<vector<int>> ostov = alg_Prima(graph);
  EXPECT_EQ(ostov[0], edg0);
  EXPECT_EQ(ostov[1], edg1);
  EXPECT_EQ(ostov[2], edg2);
  EXPECT_EQ(ostov[3], edg3);
  EXPECT_EQ(ostov[4], edg6);
}
