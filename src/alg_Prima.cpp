#include "alg_Prima.h"
#include "Heap.h"

tuple<int, int, int> Edge(vector<int> s) {
  int vertex1;
  int vertex2;
  int j = 0;
  for (int i = 1; i < s.size() && j < 3; ++i) {
    if (s[i] == 1) {
      if (j == 0) {
        vertex1 = i;
        ++j;
      } else {
         if (j == 1) {
          vertex2 = i;
          ++j;
      }
      }
    }
  }
  tuple<int, int, int>  r = std::make_tuple(s[0], vertex1, vertex2);
  return r;
}

vector<vector<int>> alg_Prima(vector<vector<int>> matr) {
  if (matr.size() != 0) {
    vector< bool > visited(matr.size());
    for (int i = 0; i < visited.size(); ++i) {
      visited[i] = false;
    }
    vector<vector<int>> ostov;
    tuple<int, int, int> edge = Edge(matr[0]);
    SixHeap<tuple<int, int, int>> h;
    h.InsertEl(edge);
    visited[0] = true;
    int n = 0;
    while (!h.isempty() && n < matr[0].size() - 2) {
      tuple<int, int, int> min_edge = h.GetMin();
      h.DeleteMin();
      vector<int> new_edge(matr[0].size());
      new_edge[0] = std::get<0>(min_edge);
      for (int i = 1; i < new_edge.size(); ++i) {
        if (i == std::get<1>(min_edge) || i == std::get<2>(min_edge)) {
          new_edge[i] = 1;
        } else {
          new_edge[i] = 0;
        }
      }
      ostov.push_back(new_edge);
      n++;
      for (int i = 0; i < matr.size(); ++i) {
        if ((matr[i][std::get<1>(min_edge)] == 1 ||
        matr[i][std::get<2>(min_edge)] == 1) && visited[i] == false) {
          h.InsertEl(Edge(matr[i]));
          visited[i] = true;
        }
      }
    }
    return ostov;
  } else {
    throw 1;
  }
}
