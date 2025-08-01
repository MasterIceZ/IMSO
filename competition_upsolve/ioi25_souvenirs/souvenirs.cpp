#include "souvenirs.h"

#include <utility>
#include <vector>

void buy_souvenirs(int N, long long P0) {
  std::pair<std::vector<int>, long long> trans = transaction(P0 - 1ll);
  std::vector<int> bought = trans.first;
  long long coins = trans.second;
  long long asking = P0 - 1ll - coins;
  if((int) bought.size() == 1) {
    transaction(asking - 1ll);
    transaction(asking - 1ll);
  }
  else {
    transaction(asking / 2ll);
  }
  return;
}
