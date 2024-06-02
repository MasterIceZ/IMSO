#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 500050;

ll a[MxN], cost[MxN], score[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}

	for(int i=1; i<=n; ++i) {
		if(a[i] >= 0) {
			score[i] = a[i];
		}
		else {
			cost[i] = -a[i];
		}
		score[i] += score[i - 1];
		cost[i] += cost[i - 1];
	}

	while(q--) {
		int stp;
		ll money;
		cin >> stp >> money;

		int idx = lower_bound(cost + 1, cost + n + 1, money + cost[stp]) - (cost + 1);

		cout << score[idx] - score[stp] << "\n";
	}

	return 0;
}
