// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

vector<int> for_adj[MxN], rev_adj[MxN];
vector<int> component_vertices[MxN], adj[MxN], inv_adj[MxN];
int visited[MxN], visited_marker, component_size[MxN], order[MxN];
stack<int> st;
int component[MxN], cnt_up, cnt_down, comp_val[MxN];
vector<int> up, down;
bool done[MxN];

void for_dfs(int u, int p) {
  visited[u] = visited_marker;
  for(auto v: for_adj[u]) {
    if(v == p || visited[v] == visited_marker) {
      continue;
    }
    for_dfs(v, u);
  }
  st.emplace(u);
}

void rev_dfs(int u, int p, int id) {
  visited[u] = visited_marker;
  component[u] = id;
  component_size[id]++;
  for(auto v: rev_adj[u]) {
    if(v == p || visited[v] == visited_marker) {
      continue;
    }
    rev_dfs(v, u, id);
  }
}

void dfs_up(int u) {
  visited[u] = visited_marker;
  // cnt_up += (int) component_vertices[u].size();
  cnt_up += component_size[u];
  up.emplace_back(u);
  for(auto v: inv_adj[u]) {
    if(visited[v] == visited_marker) {
      continue;
    }
    dfs_up(v);
  }
}

void dfs_down(int u) {
  visited[u] = visited_marker;
  // cnt_down += (int) component_vertices[u].size();
  cnt_down += component_size[u];
  down.emplace_back(u);
  for(auto v: adj[u]) {
    if(visited[v] == visited_marker) {
      continue;
    }
    dfs_down(v);
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    for_adj[u].emplace_back(v);
    rev_adj[v].emplace_back(u);
  }
  ++visited_marker;
  for(int i=1; i<=n; ++i) {
    if(visited[i] == visited_marker) {
      continue;
    }
    for_dfs(i, 0);
  }
  ++visited_marker;
  int id = 0;
  while(!st.empty()) {
    int u = st.top();
    st.pop();
    if(visited[u] == visited_marker) {
      continue;
    }
    rev_dfs(u, 0, ++id);
  }
  for(int u=1; u<=n; ++u) {
    component_vertices[component[u]].emplace_back(u);
    for(auto v: for_adj[u]) {
      adj[component[u]].emplace_back(component[v]);
      inv_adj[component[v]].emplace_back(component[u]);
    }
  }
  for(int u=1; u<=id; ++u) {
    sort(adj[u].begin(), adj[u].end());
    adj[u].resize(unique(adj[u].begin(), adj[u].end()) - adj[u].begin());
    sort(inv_adj[u].begin(), inv_adj[u].end());
    inv_adj[u].resize(unique(inv_adj[u].begin(), inv_adj[u].end()) - inv_adj[u].begin());
  
    order[u] = u;
  }
  random_device rd;
  mt19937 rnd(rd());
  shuffle(order + 1, order + id + 1, rnd);
  int answer = 1e9 + 100;
  for(int i=1; i<=id; ++i) {
    int u = order[i];
    if(done[u]) {
      continue;
    }
    cnt_up = cnt_down = 0;
    up.clear();
    down.clear();
    ++visited_marker;
    dfs_down(u);
    ++visited_marker;
    dfs_up(u);
    comp_val[u] = abs(cnt_up - cnt_down);
    answer = min(answer, comp_val[u]);
    if(cnt_up <= cnt_down) {
      for(auto v: up) {
        if(v == u) {
          continue;
        }
        done[v] = true;
      }
    }
    if(cnt_down <= cnt_up) {
      for(auto v: down) {
        if(v == u) {
          continue;
        }
        done[v] = true;
      }
    }
  }
  vector<int> answer_vector;
  for(int u=1; u<=id; ++u) {
    if(done[u] || answer != comp_val[u]) {
      continue;
    }
    for(auto v: component_vertices[u]) {
      answer_vector.emplace_back(v);
    }
  }
  sort(answer_vector.begin(), answer_vector.end());
  for(auto x: answer_vector) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}