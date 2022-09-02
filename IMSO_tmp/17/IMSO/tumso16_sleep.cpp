/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso16_sleep
 * ALGO		: Segment Tree
 * DATE		: 2 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

/*

const int MxN = 100100;
int tree[4 * MxN], lazy[4 * MxN];
int max_N;

void lzy(int x){
	if(lazy[x]){
		lazy[x * 2] += lazy[x];
		lazy[x * 2 + 1] += lazy[x];
		tree[x * 2] += lazy[x];
		tree[x * 2 + 1] += lazy[x];
		lazy[x] = 0;
	}
}

void update(int l, int r, int wl, int wr, int v, int now){
	if(l > r || l > wr || r < wl){
		return ;
	}
	if(wl <= l && r <= wr){
		tree[now] += v;
		lazy[now] += v;
		return ;
	}
	lzy(now);
	int mid = (l + r) >> 1;
	update(l, mid, wl, wr, v, now * 2);
	update(mid + 1, r, wl, wr, v, now * 2 + 1);
	tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
}

int Read(int l, int r, int wl, int wr, int now){
	if(l > r || l > wr || r < wl){
		return 0;
	}
	if(wl <= l && r <= wr){
		return tree[now];
	}
	int mid = (l + r) >> 1;
	lzy(now);
	return max(Read(l, mid, wl, wr, now * 2), Read(mid + 1, r, wl, wr, now * 2 + 1));
}

int read_range(int l, int r){
	return Read(1, max_N, l, r, 1);
}

int read_point(int i){
	return Read(1, max_N, i, i, 1);
}

// Segment Tree (NlogN) 70 %
void solve(){
	int n, l, r;
	cin >> n;
	vector<pair<int, int>> query;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		l++, r++;
		query.emplace_back(l, r);
		max_N = max(max_N, r);
	}
	sort(query.begin(), query.end());
	for(auto x: query){
		update(1, max_N, x.first, x.second, 1, 1);
	}
	int RRR = read_range(1, max_N);
	cout << (RRR == n ? "yes ": "no ");
	for(int i=1; i<=max_N; ++i){
		int now = read_point(i);
		dbg(i, now);
		if(RRR == now){
			cout << i - 1;
			return ;
		}
	}
	return ;
}

*/

const int MxN = 100100;
int dp[MxN], max_N;

void solve(){
	int n, l, r;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		dp[l]++;
		dp[r]--;
		max_N = max({max_N, r, l});
	}
	int mx = 0, idx = 0;
	for(int i=0; i<=max_N; ++i){
		dp[i] += dp[i - 1];
		if(dp[i] == n){
			cout << "yes " << i;
			return ;
		}
		if(dp[i] > mx){
			mx = dp[i];
			idx = i;
		}
	}
	cout << "no " << idx;
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
