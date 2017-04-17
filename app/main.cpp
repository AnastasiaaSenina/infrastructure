#include <iostream>
#include "add.h"
#include "Heap.h"
#include "PriorityQueue_RBtree.h"
using std::pair;
using std:: vector;
using std:: make_pair;

vector< int > FindShortestWay(int start, int n,
  vector < vector < pair < int, int > > > g) {
  vector < int > d(n, 1000000);
  d[start] = 0;
   H_PriorityQueue < pair < int, int> > q;
  int len;
  q.InsertEl(make_pair(d[start], start));
  while (!q.isempty()) {
    int current_node = q.GetMin().second;
    q.DeleteMin();
    for (unsigned int j = 0; j < g[current_node].size(); ++j) {
      int node = g[current_node][j].second;
      len = g[current_node][j].first;
      if (d[current_node] + len < d[node]) {
        q.erase(make_pair(d[node], node));
        d[node] = d[current_node] + len;
        q.insert(std::make_pair(d[node], node));
      }
    }
  }
  return d;
}

int main() {
  H_PriorityQueue<int> a;
  a.InsertEl(5);
  a.InsertEl(8);
  a.InsertEl(4);
  int res = a.FindMin();


}