#include "way.h"
#include <iostream>

int main() {
  vector < vector < std:: pair < int, int > > > tree;
  vector < pair < int, int> > node0(2);
  vector < pair < int, int> > node1(3);
  vector < pair < int, int> > node2(2);
  vector < pair < int, int> > node3(2);

  node0[0].first = 1;
  node0[0].second = 2;

  node0[1].first = 3;
  node0[1].second = 1;

  tree.push_back(node0);

  node1[0].first = 3;
  node1[0].second = 0;

  node1[1].first = 1;
  node1[1].second = 2;

  node1[2].first = 1;
  node1[2].second = 3;

  tree.push_back(node1);

  node2[0].first = 1;
  node2[0].second = 0;

  node2[1].first = 10;
  node2[1].second = 3;

  tree.push_back(node2);


  node3[0].first = 10;
  node3[0].second = 2;

  node3[1].first = 1;
  node3[1].second = 1;

  tree.push_back(node3);

  vector < int > dr(4);
  dr = FindShortestWay(0, 4, tree);
}
