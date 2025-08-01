#include "souvenirs.h"

#include <utility>
#include <vector>

void buy_souvenirs(int N, long long P0) {
  for(int i=1; i<N; ++i) {
    for(int j=1; j<=N-i; ++j) {
      transaction(i);
    }
  }
  return;
}
