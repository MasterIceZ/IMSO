#include "triples.h"

#include <vector>

long long count_triples(std::vector<int> H) {
  long long cnt = 0ll;
  for(int i=2; i<(int) H.size(); ++i) {
    if(i - H[i] < 0) {
      continue;
    }
    if(H[i - H[i]] == H[i]) {
      continue;
    }
    if(H[i - H[u]])
  }
}

std::vector<int> construct_range(int M, int K) {
  
}
