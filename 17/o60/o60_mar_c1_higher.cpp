/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o60_mar_c1_higher
 * ALGO		: Segment Tree, Binary Search
 * DATE		: 4 Jan 2022
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1000100;
int tree[MxN * 4];

void update(int l, int r, int idx, int v, int now){
	if(l > r || idx < l || idx > r){
		return ;
	}
	if(l == r){
		tree[now] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	update(l, mid, idx, v, now * 2);
	update(mid + 1, r, idx, v, now * 2 + 1);
	tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
}

int read_range(int l, int r, int wl, int wr, int now){
	if(l > r || wl > r || wr < l){
		return -1e9;
	}
	if(wl <= l && r <= wr){
		return tree[now];
	}
	int mid = (l + r) >> 1;
	return max(read_range(l, mid, wl, wr, now * 2), read_range(mid + 1, r, wl, wr, now * 2 + 1));
}

void solve(){
	int n, m;
	cin >> n >> m;
	while(m--){
		int x, h;
		cin >> x >> h;
		x += 1;
		update(1, n, x, h, 1);
		int l = 0, r = n;
		while(l < r){
			int mid = (l + r + 1) >> 1;
//			dbg(mid, l, r);
			if(read_range(1, n, max(x - mid, 1), min(x + mid, n), 1) <= h){
				l = mid;
			}
			else{
				r = mid - 1;
			}
		}
		cout << l << "\n";
	}
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
