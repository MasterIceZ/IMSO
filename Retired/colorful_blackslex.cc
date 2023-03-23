#include<bits/stdc++.h>
using namespace std;
const int N = 1005, C = 10, M = 1e6 + 3;
int n, m, c, x, y, a[N], dp[N][1 << C], ans;
vector<int> v[N], u[N];
int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) cin >> a[i], dp[i][1 << a[i]] = 1;
    for (int i = 1; i < (1 << c); i++) u[__builtin_popcount(i)].emplace_back(i);
    //for (int i = 1; i < (1 << c); i++) u[__builtin_popcount(i)].push_back(i);
    while (m--) {
        cin >> x >> y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
        //v[x].push_back(y);
        //v[y].push_back(x);
    }
    for (int i = 2; i <= c; i++) {
        for (auto e: u[i]) {
            for (int j = 0; j < n; j++) {
                if (!(e & (1 << a[j]))) continue;
                for (auto f: v[j]) dp[j][e] += dp[f][e ^ (1 << a[j])], dp[j][e] %= M;
            }
        }
    }
    for (int i = 0; i < n; i++) ans += dp[i][(1 << c) - 1], ans %= M;
    cout << ans;
}
