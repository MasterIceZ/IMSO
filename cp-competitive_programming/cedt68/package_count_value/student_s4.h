#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>
#include <vector>
#include <map>

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  std::vector<size_t> r;
  //write your code here
  
  std::map<int, size_t> freq;
  for(auto [f, s]: data) {
    freq[s]++;
  }
  for(auto [l, h]: queries) {
    size_t count = 0;
    for(auto it = freq.lower_bound(l); it != freq.upper_bound(h); ++it) {
      count += it->second;
    }
    r.emplace_back(count);
  }

  return r;
}

#endif
