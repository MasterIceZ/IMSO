#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>
#include <vector>
#include <map>

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here

  auto val = data.begin()->second;

  for(auto [l, h]: queries) {
    r.emplace_back(l <= val && val <= h);
  }

  return r;
}

#endif
