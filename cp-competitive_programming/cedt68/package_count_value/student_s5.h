#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>
#include <cassert>
#include <vector>
#include <map>

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here
  
  std::vector<int> helper(data.size());
  for(auto [f, s]: data) {
    if(f != s) {
      assert(false);
    }
    helper.emplace_back(s);
  }
  for(auto [l, h]: queries) {
    r.emplace_back(std::upper_bound(helper.begin(), helper.end(), h) - std::lower_bound(helper.begin(), helper.end(), l));
  }
  return r;
}

#endif
