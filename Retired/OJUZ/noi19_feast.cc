/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: NOI19_feast
 * ALGO		: 
 * DATE		:
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 300030;

int n, k;
ll a[MxN];
pair<ll, int> dp[2][MxN];

// dp[0][i] = not eat i, (max sum, number of people)
// dp[1][i] = eat i, (max sum, number of people)

// make sure every people consume at least [mid]
// max sum contains remainder of [value of eating - mid * number of eating]
inline pair<ll, int> calc(ll mid) {
	dp[0][1] = {0, 0};
	dp[1][1] = {a[1] - mid, 1};
	for(int i=2; i<=n; ++i) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[1][i] = max(
			make_pair(dp[0][i - 1].first - mid, dp[0][i - 1].second + 1),
			dp[1][i - 1]
		);
		dp[1][i].first += a[i];
	}
	return max(dp[0][n], dp[1][n]);
}

inline void solution(){
	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	ll l = 0ll, r = 1e18 + 100;
	while(l < r) {
		ll mid = (l + r + 1ll) >> 1ll;
		pair<ll, int> current_maximum_possible = calc(mid);
		if(current_maximum_possible.second >= k) {
			l = mid;
		}
		else {
			r = mid - 1ll;
		}
	}
	pair<ll, int> answer = calc(l);
	cout << answer.first + l * answer.second;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
