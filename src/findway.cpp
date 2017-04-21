#include "findway.h"

char* minway(int x1, int y1) {
  int x = fabs(x1);
  int y = fabs(y1);
  char* resmas = new char[10000];
  int x0 = 0;
  int y0 = 0;
  int step = 1;
  int s = 0;
  if (x1 == 0 && y1 == 0) {
    return nullptr;
  }
  while (x0 + step < x && y0 + step + 1 < y) {
    y0 = y0+step;
    step++;
    resmas[s] = 'N';
    s++;
    x0 = x0+step;
    step++;
    resmas[s] = 'E';
    s++;
  }
  step--;
    int a = x-x0;
    for ( int i = 0; i < a; i++ ) {
      x0 -= step;
      step++;
      resmas[s] = 'W';
      s++;
      x0 += step;
      step++;
      resmas[s] = 'E';
      s++;
    }
    a = y-y0;
    for (int i = 0; i < a; i++) {
        y0 -= step;
        step++;
        resmas[s] = 'S';
        s++;
        y0 += step;
        step++;
        resmas[s] = 'N';
        s++;
      }
  resmas[s] = 0;
  if (x1 < 0) {
    for (int i = 0; i < s; i++) {
      if (resmas[i] == 'E') {
        resmas[i] = 'W';
      } else {
        if (resmas[i] == 'W') {
         resmas[i] = 'E';
        }
      }
    }
  }
  if (y1 < 0) {
    for (int i = 0; i < s; i++) {
      if (resmas[i] == 'N') {
        resmas[i] = 'S';
      } else {
        if (resmas[i] == 'S') {
          resmas[i] = 'N';
        }
      }
    }
  }
      return resmas;
}
