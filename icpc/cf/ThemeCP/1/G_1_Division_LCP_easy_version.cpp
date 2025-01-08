#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int n, m, l, r, pi_table[MxN];
string s;

inline void build_kmp_table(string text) {
  m = (int) text.size() - 1;
  for(int i=1; i<=m; ++i) {
    pi_table[i] = 0;
  }
  for(int i=2, j=0; i<=m; ++i) {
    while(j > 0 && text[i] != text[j + 1]) {
      j = pi_table[j];
    }
    if (text[i] == text[j + 1]) {
      j++;
    }
    pi_table[i] = j;
  }
}

int kmp_find_count(string pattern) {
  int count_found = 0;
  for(int i=1, j=0; i<=n; ++i) {
    while(j > 0 && pattern[j + 1] != s[i]) {
      j = pi_table[j];
    }
    if(pattern[j + 1] == s[i]) {
      j++;
    }
    if(j == m) {
      count_found++;
      j = 0;
    }
  }
  return count_found;
}

inline bool ok(int mid) {
  string checking = " ";
  for(int i=1; i<=mid; ++i) {
    checking += s[i];
  }
  build_kmp_table(checking);
  int cnt = kmp_find_count(checking);
  return cnt >= l;
}

inline void solve() {
  cin >> n >> l >> r >> s;
  s = " " + s;
  int lb = 0, rb = n, answer = 0;
  while(lb <= rb) {
    int mid = (lb + rb) >> 1;
    if(ok(mid)) {
      lb = mid + 1;
      answer = mid;
    }
    else {
      rb = mid - 1;
    }
  }
  cout << answer << "\n";
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