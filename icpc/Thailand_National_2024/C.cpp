#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;

int a[MxN][MxN], mid;

struct hopcroft_karp {
	int n, m;
	vector<vector<int>> adj;
	vector<int> l, r, dist, cur;
	void add_edge(int u, int v) {
		adj[u].emplace_back(v);
	}
	void bfs() {
		queue<int> q;
		for(int i=0; i<n; ++i) {
			if(l[i] == -1) {
				q.emplace(i);
				dist[i] = 0;
			}
			else {
				dist[i] = -1;
			}
		}
		while(!q.empty()) {
			int now = q.front(); q.pop();
			for(auto x: adj[now]) {
        if(a[now][x] > mid) {
          continue;
        }
				if(r[x] != -1 && dist[r[x]] == -1) {
					dist[r[x]] = dist[now] + 1;
					q.emplace(r[x]);
				}
			}
		}
	}
	bool dfs(int u) {
		for(int &i=cur[u]; i<(int) adj[u].size(); ++i) {
			int v = adj[u][i];
      if(a[u][v] > mid) {
        continue;
      }
			if(r[v] == -1 || dist[r[v]] == dist[u] + 1 && dfs(r[v])) {
				l[u] = v;
				r[v] = u;
				return true;
			}
		}
		return false;
	}
	int max_matching() {
		int match = 0;
		while(1) {
			bfs();
			fill(cur.begin(), cur.end(), 0);
			int cnt = 0;
			for(int u=0; u<n; ++u) {
				if(l[u] == -1) {
					 cnt += dfs(u);
				}
			}
			if(cnt == 0) {
				break;
			}
			match += cnt;
		}
		return match;
	}
	hopcroft_karp(int _n, int _m):
		n(_n), m(_m), adj(_n), l(_n, -1), r(_m, -1), dist(_n, 0), cur(_n, 0) {}
};

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  hopcroft_karp mbm(n + 1, m + 1);
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
      mbm.add_edge(i, j);
    }
  }
  int l = 1, r = 1e9;
  // while(l < r) {
  //   mid = (l + r) >> 1;
  //   int match = mbm.max_matching();
  //   if(match < n) {
  //     l = mid + 1;
  //   }
  //   else {
  //     r = mid;
  //   }
  // }
  mid = 3;
  mbm.max_matching();
  cout << 3 << "\n";
  for(int i=1; i<=n; ++i) {
    cout << mbm.l[i] << " ";
  }
  return 0;
}