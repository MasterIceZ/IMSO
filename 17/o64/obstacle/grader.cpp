#include "obstacle.h"
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  vector<vector<int>> rowlen(N, vector<int>(M-1));
  vector<vector<int>> collen(N-1, vector<int>(M));
  for (auto &vec : rowlen) 
    for (auto &v : vec) 
      scanf("%d", &v);
  for (auto &vec : collen) 
    for (auto &v : vec) 
      scanf("%d", &v);
  vector<pair<int, int>> query;
  for (int i = 0; i < Q; ++i) {
    int r, c; scanf("%d %d", &r, &c);
    query.emplace_back(r, c);
  }
  initialize(N, M, Q, rowlen, collen);
  for (auto x : query) {
    printf("%d\n", ask(x.first, x.second));
  }
}

