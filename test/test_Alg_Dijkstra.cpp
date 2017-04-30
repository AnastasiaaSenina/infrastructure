#include <gtest/gtest.h>
#include "Alg_Dijkstra.h"

using std:: pair;
using std:: vector;


TEST(Alg_Dijkstra_H, Test1) {
  vector < int > res;
  res.push_back(0);
  res.push_back(3);
  res.push_back(10);
  res.push_back(10);
  res.push_back(18);

  vector < vector < pair < int, int > > > tree;
  vector < pair < int, int> > node0(2);
  vector < pair < int, int> > node1(1);
  vector < pair < int, int> > node2(3);
  vector < pair < int, int> > node3(1);
  vector < pair < int, int> > node4(1);
  node0[0] = make_pair(3, 1);
  node0[1] = make_pair(10, 3);
  tree.push_back(node0);

  node1[0] = make_pair(7, 2);
  tree.push_back(node1);

  node2[0] = make_pair(1, 0);
  node2[1] = make_pair(11, 4);
  node2[2] = make_pair(2, 3);
  tree.push_back(node2);

  node3[0] = make_pair(8, 4);
  tree.push_back(node3);

  node4[0] = make_pair(5, 1);
  tree.push_back(node4);

  vector < int > result(5);

  result = Dijkstra_H(0, tree);

  EXPECT_EQ(result, res);
}

TEST(Alg_Dijkstra_RBTRee, Test2) {
  vector < int > res;
  res.push_back(0);
  res.push_back(3);
  res.push_back(10);
  res.push_back(10);
  res.push_back(18);

  vector < vector < pair < int, int > > > tree;
  vector < pair < int, int> > node0(2);
  vector < pair < int, int> > node1(1);
  vector < pair < int, int> > node2(3);
  vector < pair < int, int> > node3(1);
  vector < pair < int, int> > node4(1);
  node0[0] = make_pair(3, 1);
  node0[1] = make_pair(10, 3);
  tree.push_back(node0);

  node1[0] = make_pair(7, 2);
  tree.push_back(node1);

  node2[0] = make_pair(1, 0);
  node2[1] = make_pair(11, 4);
  node2[2] = make_pair(2, 3);
  tree.push_back(node2);

  node3[0] = make_pair(8, 4);
  tree.push_back(node3);

  node4[0] = make_pair(5, 1);
  tree.push_back(node4);

  vector < int > result(5);

  result = Dijkstra_RB(0, tree);

  EXPECT_EQ(result, res);
}

TEST(Alg_Dijkstra_RBTRee, Test3) {
  vector < int > res;
  res.push_back(0);
  res.push_back(3);
  res.push_back(1);
  res.push_back(4);

  vector < vector < pair < int, int > > > tree;
  vector < pair < int, int> > node0(2);
  vector < pair < int, int> > node1(3);
  vector < pair < int, int> > node2(2);
  vector < pair < int, int> > node3(2);
  node0[0] = make_pair(1, 2);
  node0[1] = make_pair(3, 1);
  tree.push_back(node0);

  node1[0] = make_pair(3, 0);
  node1[1] = make_pair(1, 2);
  node1[2] = make_pair(1, 3);
  tree.push_back(node1);

  node2[0] = make_pair(1, 0);
  node2[1] = make_pair(10, 3);
  tree.push_back(node2);

  node3[0] = make_pair(10, 2);
  node3[1] = make_pair(1, 1);
  tree.push_back(node3);

  vector < int > result(4);
  result = Dijkstra_RB(0, tree);

  EXPECT_EQ(result, res);
}


TEST(Alg_Dijkstra_RBTRee, Test4) {
  vector < int > res;
  res.push_back(0);
  res.push_back(14);
  res.push_back(1000000);
  res.push_back(9);
  res.push_back(11);
  res.push_back(8);

  vector < vector < pair < int, int > > > tree;
  vector < pair < int, int> > node0(1);
  vector < pair < int, int> > node1(2);
  vector < pair < int, int> > node2(2);
  vector < pair < int, int> > node3(1);
  vector < pair < int, int> > node4(1);
  vector < pair < int, int> > node5(1);
  node0[0] = make_pair(8, 5);
  tree.push_back(node0);

  node1[0] = make_pair(1, 0);
  node1[1] = make_pair(7, 5);
  tree.push_back(node1);

  node2[0] = make_pair(5, 1);
  node2[1] = make_pair(5, 0);
  tree.push_back(node2);

  node3[0] = make_pair(2, 4);
  tree.push_back(node3);

  node4[0] = make_pair(3, 1);
  tree.push_back(node4);

  node5[0] = make_pair(1, 3);
  tree.push_back(node5);

  vector < int > result(4);
  result = Dijkstra_RB(0, tree);

  EXPECT_EQ(result, res);
}

TEST(Alg_Dijkstra_H, Test4) {
  vector < int > res;
  res.push_back(0);
  res.push_back(3);
  res.push_back(1);
  res.push_back(4);

  vector < vector < pair < int, int > > > tree;
  vector < pair < int, int> > node0(2);
  vector < pair < int, int> > node1(3);
  vector < pair < int, int> > node2(2);
  vector < pair < int, int> > node3(2);
  node0[0] = make_pair(1, 2);
  node0[1] = make_pair(3, 1);
  tree.push_back(node0);

  node1[0] = make_pair(3, 0);
  node1[1] = make_pair(1, 2);
  node1[2] = make_pair(1, 3);
  tree.push_back(node1);

  node2[0] = make_pair(1, 0);
  node2[1] = make_pair(10, 3);
  tree.push_back(node2);

  node3[0] = make_pair(10, 2);
  node3[1] = make_pair(1, 1);
  tree.push_back(node3);

  vector < int > result(4);
  result = Dijkstra_H(0, tree);

  EXPECT_EQ(result, res);
}

TEST(Alg_Dijkstra_H, Test5) {
  vector < int > res;
  res.push_back(0);
  res.push_back(14);
  res.push_back(1000000);
  res.push_back(9);
  res.push_back(11);
  res.push_back(8);

  vector < vector < pair < int, int > > > tree;
  vector < pair < int, int> > node0(1);
  vector < pair < int, int> > node1(2);
  vector < pair < int, int> > node2(2);
  vector < pair < int, int> > node3(1);
  vector < pair < int, int> > node4(1);
  vector < pair < int, int> > node5(1);
  node0[0] = make_pair(8, 5);
  tree.push_back(node0);

  node1[0] = make_pair(1, 0);
  node1[1] = make_pair(7, 5);
  tree.push_back(node1);

  node2[0] = make_pair(5, 1);
  node2[1] = make_pair(5, 0);
  tree.push_back(node2);

  node3[0] = make_pair(2, 4);
  tree.push_back(node3);

  node4[0] = make_pair(3, 1);
  tree.push_back(node4);

  node5[0] = make_pair(1, 3);
  tree.push_back(node5);

  vector < int > result(4);
  result = Dijkstra_H(0, tree);

  EXPECT_EQ(result, res);
}

