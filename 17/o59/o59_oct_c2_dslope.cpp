/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_oct_c2_dslope
 * ALGO		: Fenwick Tree, Dynamic Programming
 * DATE		: 5 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 80080;
const ll MOD = 1e9 - 1;

struct Fenwick{
	ll tree[MxN];
	void update(int idx, ll v){
		for(; idx<=80000; idx+=idx&-idx){
			tree[idx] += v;
			tree[idx] %= MOD;
		}
	}
	ll read(int idx){
		ll res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
			res %= MOD;
		}
		return res;
	}
} fw[44];
ll x;

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> x;
		fw[1].update(x, 1);
		for(int state=2; state<=k; ++state){
			ll to_update = (fw[state - 1].read(n) - fw[state - 1].read(x) + MOD) % MOD;
			fw[state].update(x, to_update);
		}
	}
	cout << fw[k].read(n);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
