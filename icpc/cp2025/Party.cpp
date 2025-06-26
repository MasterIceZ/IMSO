#include <algorithm>
#include <iostream>
#include <vector>

const int MxN = 2020;

std::vector<int> adj[MxN];
int answer;

void dfs(int u, int lvl) {
  answer = std::max(answer, lvl);
  for(auto v: adj[u]) {
    dfs(v, lvl + 1);
  }
}

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> stps;
  for(int i=1, x; i<=n; ++i) {
    std::cin >> x;
    if(x != -1) {
      adj[x].emplace_back(i);
    }
    else {
      stps.emplace_back(i);
    }
  }
  for(auto stp: stps) {
    dfs(stp, 1);
  }
  std::cout << answer << "\n";
  return 0;
}