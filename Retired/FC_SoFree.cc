/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_SoFree
 * ALGO		: Dynamic Programming
 * DATE		: 18 Feb 2023
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

const int MxN = 2020;
const ll MOD = 1e9 + 7;
ll dp[4096], c[4096];
int a[4096];

inline void solution(){
	int n, q;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cin >> q;
	if(q >= 4096){
		cout << "0";
		return ;
	}
	for(int i=1; i<=n; ++i){
		ll cnt = 1ll;
		while(a[i] == a[i + 1]){
			i++;
			cnt++;
		}
		memset(c, 0ll, sizeof c);
		c[a[i]] += cnt;
		for(int j=0; j<4096; ++j){
			if(dp[j] == 0){
				continue;
			}
			c[j ^ a[i]] = (c[j ^ a[i]] + ((dp[j] * cnt) % MOD)) % MOD;
		}
		for(int j=0; j<4096; ++j){
			dp[j] = (dp[j] + c[j]) % MOD;
		}
	}
	cout << dp[q];
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
