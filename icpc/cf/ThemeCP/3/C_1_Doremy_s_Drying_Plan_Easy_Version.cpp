#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

vector<pair<int, bool>> event[MxN];
int able_to_remove[MxN];

inline void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=1, l, r; i<=m; ++i) {
    cin >> l >> r;
    event[l].emplace_back(i, true);
    event[r + 1].emplace_back(i, false);
  }
  set<int> line;
  int base = 0;
  map<pair<int, int>, int> removing_range;
  for(int i=1; i<=n; ++i) {
    for(auto e: event[i]) {
      if(e.second == true) {
        line.emplace(e.first);
      }
      else {
        line.erase(e.first);
      }
    }
    if((int) line.size() == 0) {
      base += 1;
    }
    else if((int) line.size() == 1) {
      able_to_remove[*line.begin()] += 1;
    }
    else if((int) line.size() == 2) {
      removing_range[make_pair(*line.begin(), *prev(line.end()))] += 1;
    }
  }
  int adding = 0;
  for(auto r: removing_range) {
    adding = max(adding, r.second + able_to_remove[r.first.first] + able_to_remove[r.first.second]);
  }
  int first_max = 0, second_max = 0;
  for(int i=1; i<=m; ++i) {
    if(second_max < able_to_remove[i]) {
      second_max = able_to_remove[i];
    }
    if(first_max < second_max) {
      swap(first_max, second_max);
    }
  }
  adding = max(adding, first_max + second_max);
  cout << base + adding << "\n";
  for(int i=1; i<=n+1; ++i) {
    event[i].clear();
  }
  for(int i=1; i<=m; ++i) {
    able_to_remove[i] = 0;
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