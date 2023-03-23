#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> adj[1010];
int dis[1010][1010], deg[1010];
void solve() {
    memset(dis, -1, sizeof dis);
    memset(deg, 0, sizeof deg);
    for (int i = 1;i <= 1000;i++) adj[i].clear();
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        if (deg[i] == 1) q.push(i);
    }
    int cnt = n;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cnt--;
        for (auto& x : adj[v]) {
            if (deg[x] == 1) continue;
            if (--deg[x] == 1) {
                q.push(x);
            }
        }
    }
    if (k == 1) {
        cout << s << " 0\n";
        return;
    }
    if (cnt == 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 1;i <= n;i++) {
        dis[i][i] = 0;
        q.emplace(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& x : adj[v]) {
                if (dis[i][x] != -1) continue;
                dis[i][x] = dis[i][v] + 1;
                q.emplace(x);
            }
        }
    }
    int mn = 2e9, idx = 0;
    for (int i = 1;i <= n;i++) {
        if (dis[s][i] == -1) continue;
        for (int j = 1;j <= n;j++) {
            if (dis[i][j] == -1) continue;
            int cnt = 0;
            for (auto& x : adj[j]) {
                if (dis[i][x] == dis[i][j]) cnt = 1e9;
                else if (dis[i][x] == dis[i][j] - 1) cnt++;
            }
            if (cnt >= 1e9) {
                if (dis[s][i] + (k - 1) * (2 * dis[i][j] + 1 - dis[s][i]) < mn) {
                    mn = dis[s][i] + (k - 1) * (2 * dis[i][j] + 1);
                    idx = i;
                }
            }
            else if (cnt >= 2) {
                if (dis[s][i] + (k - 1) * (2 * dis[i][j] - dis[s][i]) < mn) {
                    mn = dis[s][i] + (k - 1) * (2 * dis[i][j]);
                    idx = i;
                }
            }
        }
    }
    if (mn == 2e9) cout << "-1\n";
    else cout << mn << ' ' << idx << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}