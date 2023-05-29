#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const int MxN = 500050;

vector<int> adj[MxN];
ll dp[MxN], fac[MxN];

void dfs(int u, int p){
	dp[u] = 1ll;
	int cnt = 0;
	for(auto v: adj[u]){
		if(v == p){
			continue;
		}
		dfs(v, u);
		dp[u] = (dp[u] * dp[v]) % MOD;
		cnt++;
	}
	dp[u] = (dp[u] * fac[cnt]) % MOD;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, x, last;
	cin >> n;
	fac[0] = 1ll;
	for(long long i=1ll; i<=(long long) n; ++i){
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	cin >> last >> x;
	int stp = last;
	adj[last].emplace_back(x);
	last = x;
	for(int i=3; i<=2*n-1; ++i){
		cin >> x;
		adj[last].emplace_back(x);
		last = x;
	}
	dfs(stp, 0);
	cout << dp[stp] << "\n";
	return 0;
}
