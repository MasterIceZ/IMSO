#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int state[MxN], in[MxN], adj[MxN];
queue<int> q;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  s = " " + s;
  for(int i=1; i<=n; ++i) {
    state[i] = s[i] - '0';
    in[i] = 0;
  }
  for(int i=1; i<=n; ++i) {
    cin >> adj[i];
    in[adj[i]]++;
  }
  vector<int> answer;
  while(!q.empty()) {
    int now = q.front(); q.pop();
    if(state[now] == 1) {
      state[now] = 0;
      state[adj[now]] = !state[adj[now]];
      answer.emplace_back(now);
    }
    if(--in[adj[now]] == 0) {
      q.emplace(adj[now]);
    }
  }
  for(int i=1; i<=n; ++i) {
    if(in[i] == 0) {
      continue;
    }
    int cur = i, l = 0, st = 0, t = 0;
    while(in[cur]) {
      if(state[cur] == 1) {
        st = !st;
      }
      in[cur] = 0;
      cur = adj[cur];
      l += 1;
      t += st;
    }
    if(st == 1) {
      cout << "-1";
      return ;
    }
    for(int j=1; j<=l; ++j) {
      if(state[cur] == 1) {
        st = !st;
      }
      if((2 * t < l) == st) {
        answer.emplace_back(cur);
      }
      cur = adj[cur];
    }
  }
  cout << answer.size() << "\n";
  for(auto x: answer) {
    cout << x << " ";
  }
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}