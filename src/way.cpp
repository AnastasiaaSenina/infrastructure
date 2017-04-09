#include "way.h"

vector< int > FindShortestWay(int start, int n, vector < vector < pair < int, int > > > g) {
  vector < int > d(n, 1000000);
  d[start] = 0;
  set < pair < int, int> > q;
  int len;
  q.insert(make_pair(d[start], start));
  while (!q.empty()) {
    int current_node = q.begin()->second;
    q.erase(q.begin());
    for (int j = 0; j < g[current_node].size(); ++j) {
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





