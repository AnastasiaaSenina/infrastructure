#include <gtest/gtest.h>
#include "multmas.h"

TEST(MultElementofMas, return_0_IfMassivIsEmpty) {
  int* res = MultElementofMas(0,0);

  EXPECT_EQ(0, res);
  }

TEST(MultElementofMas, returncorrectdata) {
  int massiv[4] = { 1, 2, 3, 4 };
  int masresright[4] = { 24, 12, 8, 6};
  int* res = MultElementofMas(massiv, 4);

  for (int i = 0; i < 4; i++)
    EXPECT_EQ(masresright[i], res[i]);
}

TEST(MultElementofMas, returncorrectdata1) {
  int massiv[4] = { 0, 2, 1, 2};
  int masresright[4] = { 4, 0, 0, 0 };
  int* res = MultElementofMas(massiv, 4);

  for (int i = 0; i < 4; i++)
    EXPECT_EQ(masresright[i], res[i]);
}
