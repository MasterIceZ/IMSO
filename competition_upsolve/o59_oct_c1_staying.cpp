#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7ll;
const int MxN = 1010;
const int MxK = 3;

vector<int> adj[MxK];
ll dp[MxK][1 << MxK][MxN][MxN];
int n, k[MxK];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int max_mask = (1 << MxK) - 1;
	adj[0] = {2};
	adj[1] = {0};
	adj[2] = {0, 1};

	cin >> n >> k[0] >> k[1] >> k[2];
	
	dp[0][1][1][1] = 1ll;
	for(int day=2; day<=n; ++day) {
		for(int mask=1; mask<=max_mask; ++mask) {
			for(int to=0; to<MxK; ++to) {
				int with_mask = (mask | (1 << to));
				for(int staying=1; staying<=k[to]; ++staying) {
					dp[to][with_mask][day][staying] = (dp[to][with_mask][day][staying] + dp[to][mask][day - 1][staying - 1]) % MOD;
				}
				for(auto from: adj[to]) {
					for(int staying=1; staying<=k[from]; ++staying) {
						dp[to][with_mask][day][1] = (dp[to][with_mask][day][1] + dp[from][mask][day - 1][staying]) % MOD;
					}
				}
			}
		}
	}
	ll answer = 0ll;
	for(int u=0; u<MxK; ++u) {
		for(int staying=1; staying<=k[u]; ++staying) {
			answer = (answer + dp[u][max_mask][n][staying]) % MOD;
		}
	}
	cout << answer << "\n";
	return 0;
}
