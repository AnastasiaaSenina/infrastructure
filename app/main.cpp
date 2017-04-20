#include <iostream>
#include "RBTree.h"
#include "Heap.h"
#include "Alg_Dijkstra.h"
#include "alg.h"
#include <stdio.h>
#include <vector>

using std:: pair;

int main() {

  printf("path to file: ");
  char path[150];
  scanf("%s", path);
  FILE* fp = fopen(path, "r");

  if (fp == 0) {
    printf("Error open file");
    return 0;
  }
  vector< vector < pair< int, int> > > g;

  int s = 0;
  int ch = 0;
  int i = 0;
  pair<int, int>* a = new pair<int, int>;
  vector<pair<int, int>>* v = new vector<pair<int, int>>;

  while ((ch = fgetc(fp)) != EOF) {
    if (ch != ' ') {
      if (ch == '\n') {
        g.push_back(*v);
        v = new vector<pair<int, int>>;
        i++;
      }
      else {
        if (s == 0) {
          a->second = ch - 48;
          s = 1;
        }
        else {
          a->first = ch - 48;
          s = 0;
          v->push_back(*a);
          a = new pair<int, int>;
        }
      }
    }
  }

  printf("Select algorithm: ");
  printf("  1 - RBTREE        2 - D-HEAP");
  int select;
  scanf("%d", &select);
  if (select == 1) {

    printf("Start node in graph: ");
    int start_node;
    scanf("%d", &start_node);

    vector<int> table_min_ways = Dijkstra_RB(start_node, g);

    printf("Minimal way:\n");
    s = table_min_ways.size();
    for (int i = 0; i < s; i++) {
      printf("%d: %d\n", i, table_min_ways[i]);
    }
  } else {
    printf("Start node in graph: ");
    int start_node;
    scanf("%d", &start_node);

    vector<int> table_min_ways = Dijkstra_H(start_node, g);

    printf("Minimal way:\n");
    s = table_min_ways.size();
    for (int i = 0; i < s; i++) {
      printf("%d: %d\n", i, table_min_ways[i]);
    }
  }
}
