#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>
#include <vector>
#include <map>

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here

  std::vector<int> helper;
  for(auto [f, s]: data) {
    helper.emplace_back(s);
  }
  std::sort(helper.begin(), helper.end());
  for(auto [l, h]: queries) {
    r.emplace_back(std::upper_bound(helper.begin(), helper.end(), h) - std::lower_bound(helper.begin(), helper.end(), l));
  }

  return r;
}

#endif
