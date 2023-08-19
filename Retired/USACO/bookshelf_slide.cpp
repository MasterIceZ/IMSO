#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int n;
ll l, w[MxN], h[MxN], dp[MxN];
deque<int> dq;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> l;
	for(int i=1; i<=n; ++i) {
		cin >> h[i] >> w[i];
		w[i] = w[i - 1] + w[i];
	}
	for(int i=1; i<=n; ++i) {
		while(!dq.empty() && h[i] > h[dq.back()]) {
			dq.pop_back();
		}
		dq.emplace_back(i);
		dp[i] = dp[i
	}
	return 0;
}
