#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

// ul, ur, dl, dr
const int di[] = {0, 0, 1, 1};
const int dj[] = {2, 3, 2, 3};
const int di2[] = {-1, -1, 1, 1};
const int dj2[] = {-1, 1, -1, 1};
const char hsh[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int rev_hsh[266];

vector<int> get_bit(int x) {
  vector<int> t;
  for(int i=0; i<6; ++i) {
    t.emplace_back(x >> i & 1);
  }
  return t;
}

void solve() {
  int n, p=0;
  string s;
  cin >> n >> s;
  vector<vector<int>> a(n, vector<int> (n, 0));
  vector<vector<array<int, 4>>> states(n, vector<array<int, 4>> (n, {-1, -1, -1, -1}));
  for(int i=0; i<(int) s.size(); ++i) {
    vector<int> t = get_bit(rev_hsh[(int) s[i]]);
    for(auto x: t) {
      if(n * n <= p) {
        break;
      }
      a[p / n][p % n] = x;
      p++;
    }
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if(a[i][j] == 0) {
        states[i][j][0] = i;
        states[i][j][2] = j;
        continue;
      }
      if(i - 1 >= 0) {
        states[i][j][0] = states[i - 1][j][0];
      }
      if(j - 1 >= 0) {
        states[i][j][2] = states[i][j - 1][2];
      }
    }
  }
  for(int i=n-1; i>=0; --i) {
    for(int j=n-1; j>=0; --j) {
      if(a[i][j] == 0) {
        states[i][j][1] = i;
        states[i][j][3] = j;
        continue;
      }
      if(i + 1 <= n - 1) {
        states[i][j][1] = states[i + 1][j][1];
      }
      if(j + 1 <= n - 1) {
        states[i][j][3] = states[i][j + 1][3];
      }
    }
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if(a[i][j] == 0) {
        continue;
      }
      for(int k=0; k<4; ++k) {
        int ii = di2[k] + i;
        int jj = dj2[k] + j;
        if(ii < 0 || ii >= n || jj < 0 || jj >= n) {
          continue;
        }
        if(states[ii][j][di[k]] != -1 && states[i][jj][dj[k]] != -1 && 0 == a[states[ii][j][di[k]]][states[i][jj][dj[k]]]) {
          cout << "YES\n";
          cout << 1 + i << " " << 1 + j << " " << 1 + states[ii][j][di[k]] << " " << 1 + states[i][jj][dj[k]];
          return ;
        }
      }
    }
  }
  cout << "NO";
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  for(int i=0; i<64; ++i) {
    rev_hsh[(int) hsh[i]] = i;
  }
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}