#include <gtest/gtest.h>
#include "way.h"

TEST(FindShortestWay, CanCorrectFindMinD) {
  vector < vector < std::pair < int, int > > > tree;
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
  result = FindShortestWay(0, 4, tree);

  vector < int > rightvar = { 0, 3, 1, 4};

  for ( int i = 0; i < 4; ++i)
    EXPECT_EQ(rightvar[i], result[i]);
}

TEST(FindShortestWay, CanCorrectFindMinD1) {
  vector < vector < std::pair < int, int > > > tree;
  vector < pair < int, int> > node0(2);
  vector < pair < int, int> > node1(1);
  vector < pair < int, int> > node2(2);
  vector < pair < int, int> > node3(1);
  node0[0] = make_pair(5, 3);
  node0[1] = make_pair(1, 2);
  tree.push_back(node0);

  node1[0] = make_pair(1, 0);
  tree.push_back(node1);

  node2[0] = make_pair(2, 1);
  node2[1] = make_pair(1, 3);
  tree.push_back(node2);

  node3[0] = make_pair(2, 1);
  tree.push_back(node3);

  vector < int > result(4);
  result = FindShortestWay(1, 4, tree);

  vector < int > rightvar = { 1, 0, 2, 3 };

  for (int i = 0; i < 4; ++i)
    EXPECT_EQ(rightvar[i], result[i]);
}
