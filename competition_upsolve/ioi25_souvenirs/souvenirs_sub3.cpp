#include "souvenirs.h"

#include <utility>
#include <vector>

void buy_souvenirs(int N, long long P0) {
  long long asking = P0 - 1ll;
  std::vector<long long> p(N, 0ll);
  for(int i=1; i<N; ++i) {
    int t = i - p[i];
    for(int j=0; j<t; ++j) {
      std::pair<std::vector<int>, long long> trans = transaction(asking);
      std::vector<int> bought = trans.first;
      long long coins = trans.second;
      for (auto e: bought) {
        p[e] += 1ll;
      }
      asking = asking - coins - (long long) bought.size() + 1ll;
    }
    asking -= 1ll;
  }
  return;
}
