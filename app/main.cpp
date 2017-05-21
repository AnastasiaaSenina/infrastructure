#include "add.h"
#include <iostream>

int main() {
  vector<pair<int,int>> a;
  a.push_back(std::make_pair(0, 1));
  a.push_back(std::make_pair(1, 2));
  a.push_back(std::make_pair(0, 2));
  vector<int> res = func(3, a);
}
