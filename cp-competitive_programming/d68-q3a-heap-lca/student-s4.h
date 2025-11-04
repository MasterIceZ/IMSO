#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library or write any helper funtion here
#include "priority_queue.h"

#include <algorithm>
#include <vector>

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
  std::vector<int> ancestors_p;
  while(p != 0) {
    ancestors_p.emplace_back(p);
    p = (p - 1) / 2;
  }
  ancestors_p.emplace_back(0);
  std::vector<int> ancestors_q;
  while(q != 0) {
    ancestors_q.emplace_back(q);
    q = (q - 1) / 2;
  }
  ancestors_q.emplace_back(0);
  for (int i=0, j=0; i<(int)ancestors_p.size() && j<(int) ancestors_q.size(); ) {
    if(ancestors_p[i] == ancestors_q[j]) {
      return ancestors_p[i];
    }
    if(ancestors_p[i] > ancestors_q[j]) {
      i++;
    }
    else {
      j++;
    }
  }
  return 0;
}

#endif
