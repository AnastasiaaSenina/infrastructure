#include "add.h"
#include "alg_Prima.h"
#include <iostream>
#include "viz.h"

int main() {
  int c;
  printf("1 - Kruskal\n2 - Prim\n");
  scanf("%d", &c);
  if (c == 1) {
    printf(" Vvedite path to file with adjacency matrix\n");
  } else {
    printf(" Vvedite path to file with incidence matrix\n");
  }
  printf("path to file: ");
  char path[150];
  scanf("%s", path);
  FILE* fp = fopen(path, "r");

  if (fp == 0) {
    printf("Error open file\n");
    return 0;
  }

  vector< vector < int > > graph;

  int ch = 0;
  vector<int>* v = new vector<int>;

  while ((ch = fgetc(fp)) != EOF) {
    if (ch != ' ') {
      if (ch == '\n') {
        graph.push_back(*v);
        v = new vector<int>;
      } else {
        v->push_back(ch - 48);
      }
    }
  }
  graph.push_back(*v);
  fclose(fp);

  vector<vector<int>> ostov;
  switch (c) {
  case 1:
   ostov = alg_krask(graph);
    viz_graph_ms(graph, ostov);
    printf("Graph was saved in graph2.gv on your desktop.\n");
    break;
  case 2:
    ostov = alg_Prima(graph);
    viz_graph_mi(graph, ostov);
    printf("Graph was saved in graph1.gv on your desktop.\n");
  }

  return 0;
}

