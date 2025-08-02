#include "triples.h"

#include <algorithm>
#include <vector>

bool is_triple(int i, int j, int k, const std::vector<int> &H) {
  std::vector<int> a = {H[i], H[j], H[k]};
  std::vector<int> b = {j - i, k - i, k - j};
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b;
}

long long count_triples(std::vector<int> H) {
  long long cnt = 0ll;
  for(int i=0; i<(int) H.size(); ++i) {
    for(int j=i+1; j<(int) H.size() && j - i <= 10; ++j) {
      for(int k=j+1; k<(int) H.size() && k - j <= 10; ++k) {
        if(!is_triple(i, j, k, H)) {
          continue;
        }
        cnt += 1ll;
      }
    }
  }
  return cnt;
}

std::vector<int> construct_range(int M, int K) {
  
}
