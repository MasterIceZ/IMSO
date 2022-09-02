/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: EC_Good Person
 * ALGO		: Inversion Conunt, Fenwick Tree, Dynamic Programming
 * DATE		: 10 Jul 2022
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

const int MxN = 100010;

struct Fenwick{
	ll tree[MxN];
	inline ll read(int idx){
		ll res = 0ll;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}	
	inline void update(int idx, ll v){
		for(; idx<=100000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	inline void clear(){
		memset(tree, 0, sizeof tree);
	}
} fw;

vector<int> types;
vector<ll> answer;
int n, a[MxN], dp[MxN], pos[MxN];
bitset<MxN> visited;

inline bool check(int X){
	bool ok = false;
	for(auto x: types){
		ok |= (x == X);
	}
	return ok;
}

inline ll inversion(){
	if(!check(1)){
		return 0ll;
	}
	fw.clear();
	ll res = 0ll;
	for(int i=n; i>=1; --i){
		fw.update(a[i], 1);
		res += fw.read(a[i] - 1);
	}
	return res;
}

inline ll insertion(){
	if(!check(2)){
		return 0ll;
	}
	ll cnt = 0ll;
	visited = 0;
	for(int i=1; i<=n; ++i){
		if(visited[i] || a[i] == i){
			continue;
		}
		int u = i, sz = 0;
		while(!visited[u]){
			visited[u] = true;
			sz++;
			u = a[u];
		}
		if(sz > 0){
			cnt += (sz - 1);
		}
	}
	return cnt;
}

inline ll lis(){
	if(!check(3)){
		return 0ll;
	}
	memset(dp, 0, sizeof dp);
	int sz = 0; 
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(dp, dp + sz, a[i]) - dp;
		dp[idx] = a[i];
		sz += (idx == sz);
	}
	return n - sz;
}

inline ll idk(){
	if(!check(4)){
		return 0ll;
	}
	for(int i=1; i<=n; ++i){
		pos[a[i]] = i;
	}
	int it = 0;
	ll cnt = 0ll;
	for(int i=n-1; i>=1; --i){
		if(pos[i + 1] > pos[i]){
			continue;
		}
		pos[i] = --it;
		cnt++;
	}
	return cnt;
}

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	answer = {inversion(), insertion(), lis(), idk()};
	for(auto x: answer){
		cout << x << " ";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int t;
	cin >> t;
	for(int i=1, x; i<=t; ++i){
		cin >> x;
		types.emplace_back(x);
	}
	sort(types.begin(), types.end());
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
