#include <bits/stdc++.h>

using namespace std;

const int MxN = 5050;

vector<int> adj[MxN];
int dist[MxN], n;
queue<int> q;

inline int bfs(int stp) {
  memset(dist, -1, sizeof dist);
  dist[stp] = 1;
  q.emplace(stp);
  int sum = 1;
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(auto x: adj[now]) {
      if(dist[x] != -1) {
        continue;
      }
      dist[x] = dist[now] + 1;
      sum += dist[x];
      q.emplace(x);
    }
  }
  for(int i=1; i<=n; ++i) {
    if(dist[i] != -1) {
      continue;
    }
    return 1e9 + 100;
  }
  return sum;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int answer = 1e9 + 100;
  cin >> n;
  for(int i=1, m; i<=n; ++i) {
    cin >> m;
    for(int _=1, x; _<=m; ++_) {
      cin >> x;
      adj[x].emplace_back(i);
    }
  }
  for(int i=1; i<=n; ++i) {
    answer = min(answer, bfs(i));
  }
  cout << answer << "\n";
  return 0;
}