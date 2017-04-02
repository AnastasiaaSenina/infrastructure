#include <gtest/gtest.h>
#include "findway.h"

TEST(Way, CanSearchCorrectWay4) {
  char* a;
  int x = -7;
  int y = -8;
  int x0 = 0;
  int y0 = 0;
  int i = 0;
  int step = 1;
  a = minway(x, y);

  while (a[i] != 0) {
    if (a[i] == 'E')
      x0+=step;
    if (a[i] == 'W')
      x0 -= step;
    if (a[i] == 'N')
      y0 += step;
    if (a[i] == 'S')
      y0 -= step;
    step++;
    i++;
  }

  EXPECT_EQ(x, x0);
  EXPECT_EQ(y, y0);
}

TEST(Way, CanSearchCorrectWay1) {
  char* a;
  int x = 10;
  int y = 15;
  int x0 = 0;
  int y0 = 0;
  int i = 0;
  int step = 1;
  a = minway(x, y);

  while (a[i] != 0) {
    if (a[i] == 'E')
      x0 += step;
    if (a[i] == 'W')
      x0 -= step;
    if (a[i] == 'N')
      y0 += step;
    if (a[i] == 'S')
      y0 -= step;
    step++;
    i++;
  }

  EXPECT_EQ(x, x0);
  EXPECT_EQ(y, y0);
}

TEST(Way, CanSearchCorrectWay2) {
  char* a;
  int x = -100;
  int y = 100;
  int x0 = 0;
  int y0 = 0;
  int i = 0;
  int step = 1;
  a = minway(x, y);

  while (a[i] != 0) {
    if (a[i] == 'E')
      x0 += step;
    if (a[i] == 'W')
      x0 -= step;
    if (a[i] == 'N')
      y0 += step;
    if (a[i] == 'S')
      y0 -= step;
    step++;
    i++;
  }

  EXPECT_EQ(x, x0);
  EXPECT_EQ(y, y0);
}
TEST(Way, CanSearchCorrectWay3) {
  char* a;
  int x = 3;
  int y = -5;
  int x0 = 0;
  int y0 = 0;
  int i = 0;
  int step = 1;
  a = minway(x, y);

  while (a[i] != 0) {
    if (a[i] == 'E')
      x0 += step;
    if (a[i] == 'W')
      x0 -= step;
    if (a[i] == 'N')
      y0 += step;
    if (a[i] == 'S')
      y0 -= step;
    step++;
    i++;
  }

  EXPECT_EQ(x, x0);
  EXPECT_EQ(y, y0);
}

TEST(Way,returnnullptrwhen00) {
  char* a;
  int x = 0;
  int y = 0;
  a = minway(x, y);

  EXPECT_EQ(a, nullptr);
}

TEST(Way, CanSearchCorrectWayRandom) {
  for (int j = 1; j < 100; j++){
    for (int k = -100; k < 1; k++) {
    char* a;
    int x = j;
    int y = k;
    int x0 = 0;
    int y0 = 0;
    int i = 0;
    int step = 1;
    a = minway(x, y);

    while (a[i] != 0) {
      if (a[i] == 'E')
        x0 += step;
      if (a[i] == 'W')
        x0 -= step;
      if (a[i] == 'N')
        y0 += step;
      if (a[i] == 'S')
        y0 -= step;
        step++;
        i++;
    }

    EXPECT_EQ(x, x0);
    EXPECT_EQ(y, y0);
   }
  }
}

