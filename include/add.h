#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#include <time.h>
#include <stdlib.h>

int Find(int* mas, int pos);
void Union(int x, int y, int* mas, int * count);
bool Percolation(int** m, int n);
double MatVer(int** m, int n, int k);
int** percolation2(int** mas, int m, int n);

#endif  // INCLUDE_ADD_H_
