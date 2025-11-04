#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library or write any helper funtion here
#include "priority_queue.h"

#include <algorithm>

template <typename T,typename Comp >
size_t CP::priority_queue<T,Comp>::get_height(size_t node) const{
  /*
    You may use this funtion
  */
}


template <typename T,typename Comp >
size_t CP::priority_queue<T,Comp>::lca(size_t p, size_t q) const {
  /*
        Secure the subtasks instead of chasing full marks.
        With best intentions, from dungeonowner :)
  */
  int answer = 0;
  auto walk_to = [&](int f, int t) {
    while(f != 0) {
      if(f == t) {
        return true;
      }
      f = (f - 1) / 2;
    }
    return f == t;
  };
  for(int i=0; i<=std::min(p, q); ++i) {
    if(walk_to(p, i) && walk_to(q, i)) {
      answer = i;
    }
  }
  return answer;
}

#endif
