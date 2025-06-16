#include "grader.h"
#include "cluedo.h"

#include <array>

void Solve(){
  std::array<int, 3> to_try = {1, 1, 1};
  while(true) {
    int r = Theory(to_try[0], to_try[1], to_try[2]);
    if(r == 0) {
      break;
    }
    to_try[--r]++;
  }
  return ;
}
