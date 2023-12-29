#include <bits/stdc++.h>

using namespace std;

const int MxN = 2020;

int n, k, s[MxN];
int in[3][MxN]; // (used, used), (used, non), (non, non) *from -> to*
bool adj[MxN][MxN];
bitset<MxN> done;
vector<int> used, non_used, c, lis;

inline void calculateInDegree() {
  for(auto from: used) {
    for(auto to: used) {
      in[0][to] += adj[from][to];
    }
  }
  for(auto from: used) {
    for(auto to: non_used) {
      in[1][to] += adj[from][to];
    }
  }
  for(auto from: non_used) {
    for(auto to: non_used) {
      in[2][to] += adj[from][to];
    }
  }
}

inline bool verify(vector<int> v) {
  for(auto x: v) {
    for(auto y: v) {
      if(adj[x][y] == 0) {
        return false;
      }
    }
  }
  return true;
}

inline bool verifyInDegree() {
  sort(used.begin(), used.end(), [](int a, int b) {
    return in[0][a] < in[0][b];
  });
  sort(non_used.begin(), non_used.end(), [](int a, int b) {
    return in[2][a] < in[2][b];
  });
  
  if(!verify(used) || !verify(non_used)) {
    return false;
  }
  return true;
}

inline void calculateLIS() {
  if(c.empty()) {
    return ;
  }

  vector<int> t;
  for(auto x: c) {
    t.emplace_back(in[1][x]);
  }

  // LIS
  for(int i=1; i<n; ++i) {
    int idx = upper_bound(lis.begin(), lis.end(), t[i]) - lis.begin();
    if(idx == (int) lis.size()) {
      lis.emplace_back(t[i]);
    }
  }
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i=1; i<=n; ++i) {
    for(int j=1, t; j<=n; ++j) {
      cin >> t;
      adj[i][j] = t;
    }
  }
  for(int i=1; i<=k; ++i) {
    cin >> s[i];
    s[i] += 1;
    used.emplace_back(s[i]);
    done[s[i]] = true;
  }
  for(int i=1; i<=n; ++i) {
    if(done[i]) {
      continue;
    }
    non_used.emplace_back(i);
  }
  calculateInDegree();
  if(!verifyInDegree()) {
    cout << "impossible\n";
    return 0;
  }
  for(auto x: non_used) {
    bool ok = true;
    for(int i=0; i<in[1][x]; ++i) {
      ok &= adj[used[i]][x];
    }
    if(!ok) {
      continue;
    }
    c.emplace_back(x);
  }
  calculateLIS();
  return 0;
}