// create with ChatGPT
// can you find the most important bridge?
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m;
vector<int> g[N];
int low[N], dfn[N], time;
vector<pair<int, int>> bridges;

void dfs(int u, int p) {
    dfn[u] = low[u] = ++time;
    for (int v : g[u]) {
        if (v == p) continue;
        if (!dfn[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == dfn[u]) {
                bridges.emplace_back(u, v);
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            dfs(i, -1);
        }
    }

    if (bridges.empty()) {
        cout << "OK!";
    } else {
        sort(bridges.rbegin(), bridges.rend());
        cout << bridges[0].first << " " << bridges[0].second;
	}
	return 0;
}
