#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

set<int> pos[3];
int cnt[3], right_position[MxN], x[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=0; i<=2; ++i) {
    pos[i].clear();
    cnt[i] = 0;
  }
  for(int i=1; i<=n; ++i) {
    cin >> x[i];
    pos[x[i]].emplace(i);
  }
  vector<pair<int, int>> todo;
  while((!pos[0].empty() && *prev(pos[0].end()) > *pos[1].begin()) || (!pos[2].empty() && *prev(pos[1].end()) > *pos[2].begin())) {
    // cerr << "IN\n";
    if(!pos[2].empty() && *pos[2].begin() < *prev(pos[1].end())) {
      int pos_2 = *pos[2].begin();
      int pos_1 = *prev(pos[1].end());
      pos[1].erase(prev(pos[1].end()));
      pos[2].erase(pos[2].begin());
      pos[1].emplace(pos_2);
      pos[2].emplace(pos_1);

      // cerr << "D: " << pos_1 << " " << pos_2 << "\n";

      todo.emplace_back(pos_1, pos_2);
    }
    if(!pos[0].empty() && *pos[1].begin() < *prev(pos[0].end())) {
      int pos_1 = *pos[1].begin();
      int pos_0 = *prev(pos[0].end());
      pos[0].erase(prev(pos[0].end()));
      pos[1].erase(pos[1].begin());
      pos[0].emplace(pos_1);
      pos[1].emplace(pos_0);

      // cerr << "D: " << pos_1 << " " << pos_0 << "\n";

      todo.emplace_back(pos_0, pos_1);
    }
  }
  cout << todo.size() << "\n";
  for(auto [x, y]: todo) {
    cout << x << " " << y << "\n";
  }
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}