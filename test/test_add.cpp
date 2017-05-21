#include <gtest/gtest.h>
#include "add.h"
TEST(IslandUF, Test1) {
  vector<vector<int>> m(4, std::vector<int>(4, 0));
  m[0][3] = 1;
  m[1][3] = 1;
  m[2][3] = 1;
  m[3][3] = 1;
  m[1][1] = 1;
  m[2][1] = 1;
  m[0][3] = 1;
  m[2][2] = 1;
  vector<vector<int>> rightres = m;
  vector<vector<int>> res = IslandUF(m);
  for (int i = 0; i < 4; ++i)
  for (int j = 0; j < 4; ++j)
    EXPECT_EQ(rightres[i][j], res[i][j]);
}

TEST(IslandUF, Test2) {
  vector<vector<int>> m(4, std::vector<int>(4, 0));
  m[0][3] = 1;
  m[1][3] = 1;
  m[2][3] = 1;
  m[3][3] = 1;
  m[1][1] = 1;
  m[2][1] = 1;
  m[0][3] = 1;
  vector<vector<int>> rightres = m;
  vector<vector<int>> res = IslandUF(m);
  rightres[1][1] = 0;
  rightres[2][1] = 0;
  for (int i = 0; i < 4; ++i)
  for (int j = 0; j < 4; ++j)
    EXPECT_EQ(rightres[i][j], res[i][j]);
}

TEST(IslandWidth, Test3) {
  vector<vector<int>> m(4, std::vector<int>(4, 0));
  m[0][3] = 1;
  m[1][3] = 1;
  m[2][3] = 1;
  m[3][3] = 1;
  m[1][1] = 1;
  m[2][1] = 1;
  m[0][3] = 1;
  vector<vector<int>> rightres = m;
  vector<vector<int>> res = IslandWidth(m);
  rightres[1][1] = 0;
  rightres[2][1] = 0;
  for (int i = 0; i < 4; ++i)
  for (int j = 0; j < 4; ++j)
    EXPECT_EQ(rightres[i][j], res[i][j]);
}

TEST(IslandWidth, Test4) {
  vector<vector<int>> m(4, std::vector<int>(4, 0));
  m[0][0] = 1;
  m[0][3] = 1;
  m[1][2] = 1;
  m[3][3] = 1;
  m[1][1] = 1;
  m[2][1] = 1;
  m[3][0] = 1;
  m[2][2] = 1;
  vector<vector<int>> rightres = m;
  vector<vector<int>> res = IslandWidth(m);
  rightres[1][1] = 0;
  rightres[2][1] = 0;
  rightres[1][2] = 0;
  rightres[2][2] = 0;
  for (int i = 0; i < 4; ++i)
  for (int j = 0; j < 4; ++j)
    EXPECT_EQ(rightres[i][j], res[i][j]);
}


