#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

pair<int, int> a[MxN];

inline void solve() {
	int n, d;
	cin >> n >> d;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].first;
	}
	for(int i=1; i<=n; ++i) {
		cin >> a[i].second;
	}
	sort(a + 1, a + n + 1);
	int answer = 0;
	ll sum = 0;
	priority_queue<int> pq;
	for(int i=1; i<=n; ++i) {
		pq.emplace(a[i].second);
		sum += (ll) a[i].second;
		while(!pq.empty() && sum + (ll) a[i].first > d) {
			sum -= pq.top(); 
			pq.pop();
		}
		answer = max(answer, (int) pq.size());
	}
	cout << answer << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}	
	return 0;
}

