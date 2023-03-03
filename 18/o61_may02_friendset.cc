/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Friend Set
 * ALGO		: Hash
 * DATE		: 25 Feb 2023
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

const ll PRIME = 1e5 + 3;
const ll MOD = 1e9 + 7;

const int MxN = 100010;
vector<ll> adj[MxN], hsh_table[MxN];
vector<pair<int, int>> edges;
map<ll, ll> cnt[MxN];
ll hsh_power[MxN], hsh_key[MxN], hsh_key_2[MxN];

inline ll get_key(int idx){
	ll res = 0ll;
	for(int i=0; i<(int) adj[idx].size(); ++i){
		res = (res + ((adj[idx][i] * hsh_power[i]) % MOD)) % MOD;
	}
	return res;
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	hsh_power[0] =  1ll;
	for(int i=1; i<MxN; ++i){
		hsh_power[i] = (hsh_power[i - 1] * PRIME) % MOD;
	}
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		edges.emplace_back(u, v);
	}
	for(int i=1; i<=n; ++i){
		sort(adj[i].begin(), adj[i].end());
		ll hsh_value = get_key(i);
		hsh_key[i] = hsh_value;
		hsh_table[adj[i].size()].emplace_back(hsh_value);

		adj[i].emplace_back(i);
		sort(adj[i].begin(), adj[i].end());
		hsh_value = get_key(i);
		hsh_key_2[i] = hsh_value;
	}
	ll answer = 0ll;
	for(int i=1; i<=n; ++i){
		if(hsh_table[i].size() == 0){
			continue;
		}
		sort(hsh_table[i].begin(), hsh_table[i].end());
		ll cnt = 1ll;
		for(int j=0; j<(int)hsh_table[i].size(); ++j){
			if(hsh_table[i][j] != hsh_table[i][j - 1]){
				answer += (cnt * (cnt - 1ll)) >> 1ll;
				cnt = 1ll;
				continue;
			}
			cnt++;
		}
		answer += (cnt * (cnt - 1)) >> 1ll;
	}
	for(auto x: edges){
		answer += (hsh_key_2[x.first] == hsh_key_2[x.second]);
	}
	cout << answer;
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
