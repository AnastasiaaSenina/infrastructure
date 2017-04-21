#include "RBTRee.h"
#include "PriorityQueue_H.h"
#include <vector>
#include <Alg_Dijkstra.h>
using std:: vector;
using std:: pair;
rbnode<pair<int, int>> NILNODE(std::make_pair(888, 888), NULL, NULL, NULL, 0);

vector< int > Dijkstra_RB(int start, vector < vector < pair <int, int> > > g) {
  int n = g.size();
  bool* m = new bool[n];
  for (int i = 0; i < n; ++i)
    m[i] = false;
  vector < int > d(n, 1000000);
  d[start] = 0;
  RB_PriorityQueue < pair < int, int> > q;
  int len;
  q.Insert(make_pair(d[start], start));
  while (!q.Isempty()) {
    int current_node = q.GetMin().second;
    q.DeleteMin();
    if (m[current_node] == false) {
      m[current_node] = true;
      for (unsigned int j = 0; j < g[current_node].size(); ++j) {
        int node = g[current_node][j].second;
        len = g[current_node][j].first;
        if (d[current_node] + len < d[node]) {
          d[node] = d[current_node] + len;
          q.Insert(std::make_pair(d[node], node));
        }
      }
    }
  }
  return d;
}

vector< int > Dijkstra_H(int start, vector < vector < pair <int, int> > > g) {
  int n = g.size();
  bool* m = new bool[n];
  for (int i = 0; i < n; ++i)
    m[i] = false;
  vector < int > d(n, 1000000);
  d[start] = 0;
  H_PriorityQueue < pair < int, int> > q;
  int len;
  q.InsertEl(make_pair(d[start], start));
  while (!q.isempty()) {
    int current_node = q.GetMin().second;
    q.DeleteMin();
    if (m[current_node] == false) {
      m[current_node] = true;
      for (unsigned int j = 0; j < g[current_node].size(); ++j) {
        int node = g[current_node][j].second;
        len = g[current_node][j].first;
        if (d[current_node] + len < d[node]) {
          d[node] = d[current_node] + len;
          q.InsertEl(std::make_pair(d[node], node));
        }
      }
    }
  }
  return d;
}
