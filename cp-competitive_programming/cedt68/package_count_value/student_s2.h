#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>
#include <vector>
#include <map>

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here
  r.emplace_back(0);

  auto [l, h] = queries[0];

  std::vector<int> helper;
  for(auto [f, s]: data) {
    if(l <= s && s <= h) {
      r.back()++;
    }
  }
  return r;
}

#endif
