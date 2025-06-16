#include "abcd.h"
#include <vector>

std::vector<char> abcd(int N) {
  std::vector<char> asking(N, 'B');
  int base = exam(asking);
  for(int i=0; i<N; ++i) {
    asking[i] = 'A';
    int ask_b = exam(asking);
    if(ask_b > base) {
      base = ask_b;
      continue;
    }
    if(ask_b < base) {
      asking[i] = 'B';
      base = ask_b + 1;
      continue;
    }
    asking[i] = 'D';
    int ask_c = exam(asking);
    if(ask_c > base) {
      base = ask_c;
      continue;
    }
    asking[i] = 'C';
    base = base + 1;
  }
  return asking;
}
