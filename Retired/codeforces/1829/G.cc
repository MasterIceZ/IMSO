/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
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

const int MxN = 2100010;
ll dp[MxN];
int layer[MxN];
bitset<MxN> isLeft, isRight;

inline void solution(){
	int n;
	cin >> n;
	ll answer = 0ll;
	for(; layer[n] > 0; ){
		answer += dp[n];
		if(isRight[n]){
			break;
		}
		n -= (layer[n] - 1);
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	

	int sum = 0;
	for(int i=1; i<=2023; ++i){
		sum += i;
		isRight[sum] = true;
		isLeft[sum + 1] = true;
	}

	dp[1] = 1ll;
	layer[1] = 1;
	for(long long i=2; i<=1000000ll; ++i){
		layer[i] = layer[i - 1];
		if(isLeft[i]){
			dp[i] = i * i;
			layer[i]++;
			continue;
		}
		dp[i] = dp[i - layer[i]] + i * i;
	}

	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
