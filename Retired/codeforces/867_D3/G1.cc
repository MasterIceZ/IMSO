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

const int MxN = 200020;
const int MxA = 1000010;
int a[MxN];
ll cnt[MxA];
vector<int> factors;

inline void solution(){
	memset(cnt, 0, sizeof cnt);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		cnt[a[i]]++;
	}
	dbg(cnt[10000], cnt[1000000]);
	ll ways = 0ll;
	for(int i=1; i<=1000000; ++i){
		if(cnt[i] == 0){
			continue;
		}
		factors.clear();
		int sq = sqrt(i);
		for(int j=1; j<=sq; ++j){
			if(i % j){
				continue;
			}
			if(j * j == i){
				factors.emplace_back(j);
			}
			else{
				factors.emplace_back(j);
				factors.emplace_back(i / j);
			}
		}
		dbg(i);
		for(auto f: factors){
			int s = i;
			ll t = (ll) s * (s / f);
			if(t > 1000000ll){
				continue;
			}
			dbg(f, s, t, cnt[f], cnt[s], cnt[t]);
			if(cnt[f] == 0 || cnt[t] == 0){
				continue;
			}
			if(s == t){
				ways += (cnt[i] * (cnt[i] - 1ll) * (cnt[i] - 2ll));
			}
			else{
				ways += (cnt[f] * cnt[s] * cnt[t]);
			}
		}
	}
	cout << ways;
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
