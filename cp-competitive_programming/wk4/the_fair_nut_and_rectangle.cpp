#include <iostream>

struct rectangle_t {
  long long x, y, a;
  
  bool operator < (const rectangle_t &o) const {
    return x < o.x;
  }

  rectangle_t(long long _x=0ll, long long _y=0ll, long long _a=0ll): 
    x(_x), y(_y), a(_a) {}
};

struct lichao_tree_t {

} lct;