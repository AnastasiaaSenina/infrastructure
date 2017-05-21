#include <gtest/gtest.h>
#include "add.h"
#include <vector>

using std::pair;
using std::vector;
using std::cout;
using std::make_pair;

TEST(func, test1) {
  vector< pair< int, int > > a;
  a.push_back(make_pair(0, 1));
  a.push_back(make_pair(1, 2));
  a.push_back(make_pair(0, 2));
  vector < int > ret = func(3, a);
  vector < int > r;
  r.push_back(0);
  r.push_back(1);
  r.push_back(2);

  EXPECT_EQ(ret, r);
}


TEST(func, test2) {
  vector< pair< int, int > > a;
  a.push_back(make_pair(0, 1));
  a.push_back(make_pair(1, 2));
  a.push_back(make_pair(0, 2));
  a.push_back(make_pair(0, 3));
  a.push_back(make_pair(2, 3));
  vector < int > ret2 = func(4, a);
  vector < int > r;
  r.push_back(0);
  r.push_back(1);
  r.push_back(2);
  r.push_back(1);

  EXPECT_EQ(ret2, r);
}

TEST(tk, throw_when_0_set) {
  vector< pair< int, int > > a;
  ASSERT_ANY_THROW(func(0, a));
}
