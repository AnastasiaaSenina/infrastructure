#include "multmas.h"
#include <iostream>

int main() {
  int massiv[4] = {1, 2, 3, 4 };
  int* res = MultElementofMas(massiv, 4);
  for ( int i = 0; i < 4; i++)
  std::cout << res[i] << "  ";
}
