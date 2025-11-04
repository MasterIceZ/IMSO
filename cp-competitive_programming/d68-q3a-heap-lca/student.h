#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library or write any helper funtion here
#include "priority_queue.h"

#include <algorithm>
#include <bitset>

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
  // Convert to 1-indexed
  p++; q++;
  
  // Align to same depth
  int clz_p = __builtin_clzll(p);
  int clz_q = __builtin_clzll(q);
  
  if(clz_p > clz_q) q >>= (clz_q - clz_p);
  else p >>= (clz_p - clz_q);
  
  // Find common ancestor - unrolled loop
  if(p != q) {
    if((p >> 1) == (q >> 1)) { p >>= 1; goto done; }
    if((p >> 2) == (q >> 2)) { p >>= 2; goto done; }
    if((p >> 3) == (q >> 3)) { p >>= 3; goto done; }
    if((p >> 4) == (q >> 4)) { p >>= 4; goto done; }
    if((p >> 5) == (q >> 5)) { p >>= 5; goto done; }
    if((p >> 6) == (q >> 6)) { p >>= 6; goto done; }
    if((p >> 7) == (q >> 7)) { p >>= 7; goto done; }
    if((p >> 8) == (q >> 8)) { p >>= 8; goto done; }
    
    // Fallback for deeper nodes
    while(p != q) { p >>= 1; q >>= 1; }
  }
  
  done:
  return p - 1;
}

#endif
