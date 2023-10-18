#include <vector>
#include <algorithm>
#include "penguin.h"

using namespace std;

void penguin(int N) {
  N = max(N - 1, 2);
  for (int i = 2; i <= N; ++i)
  {
    if(play({i})) {
      return;
    }
  }
  for (int i = N; i >= 2; --i)
  {
    if(play({i})) {
      return;
    }
  }
  return;
}