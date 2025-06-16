#include "icecream.h"

#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

#include <iostream>

const long long MOD = 1e9 + 7ll;
const int MxN = 11;

int root;
long long mem[MxN][MxN][MxN];

inline std::vector<std::pair<int, int>> find_adding(const std::vector<int> &perm, const std::vector<int> &P) {
  std::vector<std::pair<int, int>> to_add;

  std::vector<int> pos(MxN, -1);
  pos[root] = 0;

  for(int i=0; i<(int) perm.size(); ++i) {
    int v = perm[i];

    pos[v] = i + 1;
    if(pos[P[v]] == -1) {
      return std::vector<std::pair<int, int>> ();
    }
    to_add.emplace_back(i + 1, pos[P[v]]);
  }
  return to_add;
}

void initialize(int N, int Q, std::vector<int> P) {
  root = std::find(P.begin(), P.end(), -1) - P.begin();

  std::vector<int> perm(N);
  std::iota(perm.begin(), perm.end(), 0);
  perm.erase(perm.begin() + root);

  do {
    std::vector<std::pair<int, int>> adding = find_adding(perm, P);

    if((int) adding.size() != N - 1) {
      continue;
    }
    for(auto [u, v]: adding) {
      int p = perm[u - 1];
      mem[p][u][v] = (mem[p][u][v] + 1ll) % MOD;
    }
  } while(std::next_permutation(perm.begin(), perm.end()));
}

long long count_perm(int x, int l1, int r1, int l2, int r2) {
  long long ways = 0ll;

  for(int i=l1; i<=r1; ++i) {
    for(int j=l2; j<=r2; ++j) {
      ways = (ways + mem[x][i][j]) % MOD;
    }
  }

  return ways;
}