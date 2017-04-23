#include "add.h"
#include <iostream>

int main() {
  int** m1 = new int*[10];
  for (int i = 0; i < 10; i++)
    m1[i] = new int[10];

  for (int j = 0; j < 10; j++)
  for (int k = 0; k < 10; k++)
    m1[j][k] = 0;


  int** m2 = new int*[5];
  for (int i = 0; i < 5; i++)
    m2[i] = new int[5];

  for (int j = 0; j < 5; j++)
  for (int k = 0; k < 5; k++)
    m2[j][k] = 0;

  double res = MatVer(m1, 10, 1000);
  std::cout << res<< std:: endl;

  res = MatVer(m1, 10, 10000);
  std::cout << res << std::endl;

  res = MatVer(m2, 5, 10000);
  std::cout << res << std::endl;

  res = MatVer(m2, 5, 100000);
  std::cout << res << std::endl;
}
