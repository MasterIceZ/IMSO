#include <bits/stdc++.h>

using namespace std;

const int MxN = 55;

int t[MxN][MxN], a[MxN], b[MxN], sum_row[MxN], sum_col[MxN];

struct min_cost_max_flow {
  const int INF = 1e9 + 100;
  vector<vector<pair<int, int>>> adj;
  vector<int> cap, cost;
  int n, m, source, sink;
  min_cost_max_flow(int _n, int _source, int _sink):
    n(n), m(0), source(_source), sink(_sink) {
      adj.assign(n, vector<pair<int, int>> ());
      cap.clear();
      cost.clear();
  }
  inline void add_edge(int u, int v, int w, int c) {
    adj[u].emplace_back(v, m);
    adj[v].emplace_back(u, m ^ 1);
    cost.emplace_back(w);
    cost.emplace_back(-w);
    cap.emplace_back(c);
    cap.emplace_back(0);
    m += 2;
  }
  inline void shortest_path(vector<int> &dist, vector<pair<int, int>> &par) {
    dist.assign(n, INF);
    par.assign(n, make_pair(-1, -1));

    queue<int> q;
    vector<bool> inq(n, false);
    q.emplace(source);
    inq[source] = true;
    while(!q.empty()) {
      int now = q.front(); q.pop();
      inq[now] = false;
      for(auto x: adj[now]) {
        int nxt_w = dist[now] + cost[x.first];
        if(cap[x.second] <= 0 || dist[x.first] <= nxt_w) {
          continue;
        }
        dist[x.first] = nxt_w;
        par[x.first] = make_pair(now, x.second);
        if(!inq[x.first]) {
          q.emplace(x.first);
          inq[x.first] = true;
        }
      }
    }
  }
  inline int solve(int k) {
    int flow = 0, sum = 0;
    vector<int> dist;
    vector<pair<int, int>> par;
    while(flow < k) {
      shortest_path(dist, par);
      if(dist[sink] == INF) {
        break;
      }
      int f = k - flow;
      for(int cur=sink; cur!=source; cur=par[cur].first) {
        f = min(f, cap[par[cur].second]);
      }
      flow += f;
      sum += f * dist[sink];
      for(int cur=sink; cur!=source; cur=par[cur].first) {
        cap[par[cur].second] -= f;
        cap[par[cur].second ^ 1] += f;
      }
    }
    if(flow < k) {
      return -1;
    }
    return sum;
  }
};

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  // for(int i=1; i<=n; ++i) {
  //   for(int j=1; j<=m; ++j) {
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      cin >> t[i][j];
      sum_row[i] += t[i][j];
      sum_col[j] += t[i][j];
    }
  }
  // for(int i=1; i<=n; ++i) {
  for(int i=0; i<n; ++i) {
    cin >> a[i];
  }
  // for(int i=1; i<=m; ++i) {
  for(int i=0; i<m; ++i) {
    cin >> b[i];
  }
  // if(accumulate(a + 1, a + n + 1, 0) != accumulate(b + 1, b + m + 1, 0)) {
  if(accumulate(a, a + n, 0) != accumulate(b, b + m, 0)) {
    cerr << "NOT SAME!";
    cout << "-1\n";
    return 0;
  }
  // int source = (n + 1) * (m + 1), sink = (n + 1) * (m + 1) + 1;
  int source = n * m, sink = n * m + 1;
  // min_cost_max_flow mcmf((n + 1) * (m + 1) + 2, source, sink);
  min_cost_max_flow mcmf(n * m + 2, source, sink);
  int total_cap = 0;
  // for(int i=1; i<=n; ++i) {
  for(int i=0; i<n; ++i) {
    if(sum_row[i] <= a[i]) {
      mcmf.add_edge(source, i, 0, a[i] - sum_row[i]);
    }
    else {
      mcmf.add_edge(i, sink, 0, sum_row[i] - a[i]);
    }
    total_cap += abs(a[i] - sum_row[i]);
  }
  // for(int j=1; j<=m; ++j) {
  for(int j=0; j<m; ++j) {
    if(sum_col[j] <= b[j]) {
      mcmf.add_edge(n + j, sink, 0, b[j] - sum_col[j]);
    }
    else {
      mcmf.add_edge(source, n + j, 0, sum_col[j] - b[j]);
    }
    total_cap += abs(b[j] - sum_col[j]);
  }
  // for(int i=1; i<=n; ++i) {
  //   for(int j=1; j<=m; ++j) {
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(t[i][j] == 1) {
        mcmf.add_edge(n + j, i, 1, 1);
      }
      else {
        mcmf.add_edge(i, n + j, 1, 1);
      }
    }
  }
  cout << mcmf.solve(total_cap / 2) << "\n";
  return 0;
}