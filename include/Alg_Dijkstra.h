#ifndef INCLUDE_ALG_DIJKSTRA_H_
#define INCLUDE_ALG_DIJKSTRA_H_
#include "PriorityQueue_H.h"
#include "RBTree.h"


using std::pair;
using std::vector;
using std::make_pair;

vector< int > Dijkstra_H(int start, vector < vector < pair <int, int> > > g);

vector< int > Dijkstra_RB(int start, vector < vector < pair <int, int> > > g);

#endif  // INCLUDE_ALG_DIJKSTRA_H_
