#include "add.h"

int Find(int* mas, int pos) {

  int i = pos;
  while (i != mas[i]) {
    i = mas[i];
  }
  return i;
}

void Union(int x, int y, int* mas, int * count) {
  int set_x = Find(mas, x);
  int set_y = Find(mas, y);

  if (count[set_x] > count[set_y]) {
    mas[set_y] = mas[set_x];
    count[set_x]++;
  } else {
    mas[set_x] = mas[set_y];
    count[set_y]++;
  }
}

bool Percolation(int** m, int n) {
  int* mas = new int[n*n];
  int* count = new int[n*n];
  for (int i = 0; i < n*n; ++i) {
    count[i] = 1;
  }
  for (int i = 0; i < n*n; ++i) {
    mas[i] = i;
  }
  for (int i = 0; i < n -1; ++i)
    Union(i, i+1, mas, count);
  for ( int i = n*n - n; i < n*n -1; i++ )
    Union(i, i + 1, mas, count);

  for (int i = 0; i < n*n; i++) {
    if (m[(i - i%n) / n][i%n] == 1) {
      if (i - 1 >= 0 && i - 1 < n*n) {
        if (m[(i-1-(i - 1)%n)/n][(i-1)%n] == 1)
          Union(i-1, i, mas, count);
      }
      if (i + 1 >= 0 && i + 1 < n*n) {
        if (m[(i + 1 - (i + 1) % n) / n][(i + 1) % n] == 1)
          Union(i + 1, i, mas, count);
      }
      if (i + n >= 0 && i + n < n*n) {
        if (m[(i + n - (n + i) % n) / n][(n + i) % n] == 1)
          Union(i + n, i, mas, count);
      }
      if (i - n >= 0 && i - n < n*n) {
        if (m[(i - n - (i - n) % n) / n][(i - n) % n] == 1)
          Union(i - n, i, mas, count);
      }
    }
  }

  if (Find(mas, 0) == Find(mas, n*n - 1)) {
    delete[] mas;
    delete[] count;
    return true;
  } else {
     delete[] mas;
     delete[] count;
     return false;
}


}
double MatVer(int** m, int n) {
  srand(time(NULL));
  double p = 0;
  int sum = 0;
  for (int i = 0; i < 1000; ++i) {
    p+=sum / (n*n);
    sum = 0;

    for (int j = 0; j < n; j++)
    for (int k = 0; k < n; k++)
      m[j][k] = 0;
    while (!Percolation(m, n)) {
      int x = rand() % n;
      int y = rand() % n;
      m[x][y] = 1;
      sum++;
    }
  }
  return p/1000;
}
