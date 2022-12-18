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

inline void solution(){
	int n;
//	cin >> n;
	scanf("%d", &n);
	vector<ll> v(n);
	unordered_map<ll, ll> mp;
	for(int i=0; i<n; ++i){
		scanf("%lld", &v[i]);
		mp[v[i]]++;
	}
//	for(auto &x: v){
//		//cin >> x;
//		mp[x]++;
//	}
	ll wx = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
	//dbg(wx);
	ll res = 0ll;
	for(auto x: mp){
		if(abs(wx - x.first) != x.first){
			res += x.second * mp[abs(wx - x.first)];
			//dbg(x.first, x.second * mp[abs(wx - x.first)]);
		}
		else{
			res += x.second * (x.second - 1ll) / 2ll;
		}
	}
	//dbg(res);
	//cout << res;
	printf("%lld", res);
	return ;
}

signed main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	scanf("%d", &q);
	while(q--){
		solution();
//		cout << "\n";
		printf("\n");
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
