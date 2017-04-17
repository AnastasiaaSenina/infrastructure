#include "add.h"
#include <iostream>
#define n   10
int main() {
  int** m = new int*[n];
  for (int i = 0; i < n; i++)
    m[i] = new int[n];

  for (int j = 0; j < n; j++)
  for (int k = 0; k < n; k++)
    m[j][k] = 0;

  double res = MatVer(m, n);
  std::cout << res;
}
