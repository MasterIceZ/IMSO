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
  size_t height = 0;
  while(node != 0) {
    node = (node - 1) / 2;
    height++;
  }
  return height;
}


template <typename T,typename Comp >
size_t CP::priority_queue<T,Comp>::lca(size_t p, size_t q) const {
  /*
        Secure the subtasks instead of chasing full marks.
        With best intentions, from dungeonowner :)
  */
  return 0;
}

#endif
