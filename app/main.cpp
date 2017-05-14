#include "add.h"
#include "alg_Prima.h"
#include <iostream>
#include "viz.h"

int main() {
 /* vector<vector<int>> graph;
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
  viz_graph_mi(graph, ostov);
    */

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
  viz_graph_ms(graph, ostov);
}
