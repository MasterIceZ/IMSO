#include <bits/stdc++.h>

using namespace std;

const int MxS = 1000010;
const int MxN = 200020;

char s[MxS];
vector<int> v, answer;
vector<pair<int, int>> adj[MxN];
bitset<MxN> visited;

bool cmpPair(pair<int, int> a, pair<int, int> b) {
  if(a.second != b.second) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

void dfs(int u, int p) {
  cerr << "current: " << u << "\n";
  visited[u] = true;
  answer.emplace_back(u);
  for(auto x: adj[u]) {
    if(x.first == p || visited[x.first]) {
      continue;
    }
    dfs(x.first, u);
  }
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, b;
  cin >> n >> m >> b;
  for(int i=1; i<=n; ++i) {
    cin >> (s + 1);
    int len = strlen(s + 1);
    cerr << "S: " << (s + 1) << "\n";
    for(int j=1; j<=len; ++j) {
      if(s[j] == '0') {
        continue;
      }
      v.emplace_back(j);
    }
    for(int j=1; j<(int) v.size(); ++j) {
      if(v[j] - v[j - 1] == m) {
        continue;
      }
      cout << "-1";
      return 0;
    }
    if(v[0] > m || len - v.back() > m) {
      cout << "-1";
      return 0;
    }
    int node_u = m - v[0], node_v = len - v.back();
    adj[node_u].emplace_back(node_v, i);
    v.clear();
  }
  for(int i=0; i<=m-1; ++i) {
    sort(adj[i].begin(), adj[i].end(), cmpPair);
    cerr << "adj[" << i << "]: ";
    for(auto x: adj[i]) {
      cerr << x.first << " ";
    }
    cerr << "\n";
  }
  cerr << "DEBUG\n";
  int stp = m - b;
  dfs(stp, -1);
  if((int) answer.size() < n) {
    cout << "-1";
    return 0;
  }
  for(auto x: answer) {
    cout << x << " ";
  }
  return 0;
}