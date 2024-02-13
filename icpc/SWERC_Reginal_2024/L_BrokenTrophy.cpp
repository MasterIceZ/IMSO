#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 300030;

int w[MxN], h[MxN], a[4][MxN];
map<pair<int, int>, vector<int>> cnt;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int k, n;
  cin >> k >> n;
  for(int i=1; i<=k; ++i) {
    cin >> w[i];
  }
  for(int i=1; i<=k; ++i) {
    cin >> h[i];
    cnt[minmax(h[i], w[i])].emplace_back(i);
  }
  int current_position = 0;
  while(!cnt[make_pair(3, 3)].empty()) {
    for(int i=1; i<=3; ++i) {
      ++current_position;
      a[1][current_position] = cnt[make_pair(3, 3)].back();
      a[2][current_position] = cnt[make_pair(3, 3)].back();
      a[3][current_position] = cnt[make_pair(3, 3)].back();
    }
    cnt[make_pair(3, 3)].pop_back();
  }
  while(!cnt[make_pair(2, 3)].empty()) {
    for(int i=1; i<=2; ++i) {
      ++current_position;
      a[1][current_position] = cnt[make_pair(2, 3)].back();
      a[2][current_position] = cnt[make_pair(2, 3)].back();
      a[3][current_position] = cnt[make_pair(2, 3)].back();
    }
    cnt[make_pair(2, 3)].pop_back();
  }
  while(!cnt[make_pair(2, 2)].empty() && !cnt[make_pair(1, 2)].empty()) {
    for(int i=1; i<=2; ++i) {
      ++current_position;
      a[1][current_position] = cnt[make_pair(1, 2)].back();
      a[2][current_position] = cnt[make_pair(2, 2)].back();
      a[3][current_position] = cnt[make_pair(2, 2)].back();
    }
    cnt[make_pair(1, 2)].pop_back();
    cnt[make_pair(2, 2)].pop_back();
  }
  int reset_position = current_position;
  while(!cnt[make_pair(2, 2)].empty()) {
    for(int i=1; i<=2; ++i) {
      ++current_position;
      a[2][current_position] = cnt[make_pair(2, 2)].back();
      a[3][current_position] = cnt[make_pair(2, 2)].back();
    }
    cnt[make_pair(2, 2)].pop_back();
  }
  while(cnt[make_pair(1, 3)].size() >= 2 && reset_position + 6 <= current_position) {
    for(int t=1; t<=2; t++) {
      for(int i=1; i<=3; ++i) {
        ++reset_position;
        a[1][reset_position] = cnt[make_pair(1, 3)].back();
      }
      cnt[make_pair(1, 3)].pop_back();
    }
  }
  while(!cnt[make_pair(1, 3)].empty() && !cnt[make_pair(1, 1)].empty() && reset_position + 4 <= current_position) {
    for(int t=1; t<=2; t++) {
      for(int i=1; i<=3; ++i) {
        ++reset_position;
        a[1][reset_position] = cnt[make_pair(1, 3)].back();
      }
      ++reset_position;
      a[1][reset_position] = cnt[make_pair(1, 1)].back();
      cnt[make_pair(1, 3)].pop_back();
      cnt[make_pair(1, 1)].pop_back();
    }
  }
  while(!cnt[make_pair(1, 1)].empty() && reset_position + 1 <= current_position) {
    ++reset_position;
    a[1][reset_position] = cnt[make_pair(1, 1)].back();
    cnt[make_pair(1, 1)].pop_back();
  }
  while(!cnt[make_pair(1, 3)].empty()) {
    ++current_position;
    a[1][current_position] = cnt[make_pair(1, 3)].back();
    a[2][current_position] = cnt[make_pair(1, 3)].back();
    a[3][current_position] = cnt[make_pair(1, 3)].back();
    cnt[make_pair(1, 3)].pop_back();
  }
  while(cnt[make_pair(1, 2)].size() >= 3) {
    for(int i=1; i<=2; ++i) {
      ++current_position;
      a[1][current_position] = cnt[make_pair(1, 2)][(int) cnt[make_pair(1, 2)].size() - 1];
      a[2][current_position] = cnt[make_pair(1, 2)][(int) cnt[make_pair(1, 2)].size() - 2];
      a[3][current_position] = cnt[make_pair(1, 2)][(int) cnt[make_pair(1, 2)].size() - 3];
    }
    cnt[make_pair(1, 2)].pop_back();
    cnt[make_pair(1, 2)].pop_back();
    cnt[make_pair(1, 2)].pop_back();
  }
  while(!cnt[make_pair(1, 2)].empty() && !cnt[make_pair(1, 1)].empty()) {
    ++current_position;
    a[1][current_position] = cnt[make_pair(1, 1)].back();
    a[2][current_position] = cnt[make_pair(1, 2)].back();
    a[3][current_position] = cnt[make_pair(1, 2)].back();
    cnt[make_pair(1, 1)].pop_back();
    cnt[make_pair(1, 2)].pop_back();
  }
  while(cnt[make_pair(1, 1)].size() >= 3) {
    ++current_position;
    a[1][current_position] = cnt[make_pair(1, 1)][(int) cnt[make_pair(1, 1)].size() - 1];
    a[2][current_position] = cnt[make_pair(1, 1)][(int) cnt[make_pair(1, 1)].size() - 2];
    a[3][current_position] = cnt[make_pair(1, 1)][(int) cnt[make_pair(1, 1)].size() - 3];
    cnt[make_pair(1, 1)].pop_back();
    cnt[make_pair(1, 1)].pop_back();
    cnt[make_pair(1, 1)].pop_back();
  }
  for(int i=1; i<=3; ++i) {
    for(int j=1; j<=n; ++j) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}