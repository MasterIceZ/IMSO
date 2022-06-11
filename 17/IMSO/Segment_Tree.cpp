/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Segment Tree
 * ALGO		: Segment Tree
 * DATE		: 14 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 270000;

struct SegTree{
	int tree[4 * MxN];
	void update(int l, int r, int idx, int val, int now){
		dbg(l, r);
		if(l > r || l > idx || r < idx){
			return ;
		}
		if(l == r){
			tree[now] = val;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, idx, val, now * 2);
		update(mid + 1, r, idx, val, now * 2 + 1);
		tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
	}
	int read(int l, int r, int wl, int wr, int now){
		dbg(l, r);
		if(l > r || l > wr || r < wl){
			return -1e9 - 10;
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		return max(read(l, mid, wl, wr, now * 2), read(mid + 1, r, wl, wr, now * 2 + 1));
	}
} seg;

void solve(){
	int n, q;
	char x;
	cin >> n >> q;
	while(q--){
		cin >> x;
		if(x == 'U'){
			int a, b;
			cin >> a >> b;
			seg.update(1, n, a, b, 1);
		}
		else{
			int a, b;
			cin >> a >> b;
			cout << seg.read(1, n, a, b, 1) << "\n";
		}
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
