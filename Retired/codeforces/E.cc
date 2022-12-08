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

const int MxN = 2e5 + 20;
ll in[MxN], cnt[MxN][2];
int a[MxN];

inline void solution(){
	memset(in, 0ll, sizeof in);
	memset(cnt, 0ll, sizeof cnt);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		cnt[i][a[i]]++;
	}
	for(int i=1; i<=n; ++i){
		cnt[i][1] += cnt[i - 1][1];
	}
	for(int i=n; i>=1; --i){
		cnt[i][0] += cnt[i + 1][0];
	}
	ll ans = 0, c = 0;
	for(int i=n; i>=1; --i){
		if(a[i] == 0){
			c++;
		}
		else{
			ans += c;
			in[i] = c;
		}
	}
	ll change = 0;
	for(int i=1; i<=n; ++i){
		// change i to !i
		if(a[i] == 1){
			change = max(change, ans - in[i] + cnt[i - 1][1]);
		}
		else{
			change = max(change, ans - cnt[i - 1][1] + cnt[i + 1][0]);
		}
	}
	cout << max(ans, change);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
