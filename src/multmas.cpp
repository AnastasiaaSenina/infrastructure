#include "multmas.h"
int* MultElementofMas(int* mas, int sizeofmas) {
  if (mas == nullptr || sizeofmas == 1) {
    return 0;
  }
  int* resmas = new int[sizeofmas];
  int right, left;
  left = 1;
  right = 1;
  for (int i = 0; i < sizeofmas; i++) {
    resmas[i] = 1;
  }
  for (int i = 0; i < sizeofmas; i++) {
    resmas[i] *= right;
    right *= mas[i];
    resmas[sizeofmas - 1 - i] *= left;
    left *= mas[sizeofmas - 1 - i];
  }
  return resmas;
}
