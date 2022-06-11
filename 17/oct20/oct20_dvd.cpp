/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct20_dvd
 * ALGO		: Segment Tree
 * DATE		: 8 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;

struct SegTree{
	pair<int, int> tree[MxN * 4];
	pair<int, int> calc(pair<int, int> a, pair<int, int> b){
		return pair<int, int>(min(a.first, b.first), max(a.second, b.second));
	}
	void build(int l, int r, int now){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[now] = pair<int, int>(l, l);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, now * 2);
		build(mid + 1, r, now * 2 + 1);
		tree[now] = pair<int, int>(tree[now * 2].first, tree[now * 2 + 1].second);
	}
	void update(int l, int r, int idx, int v, int now){
		if(l > r || r < idx || l > idx){
			return ;
		}
		if(l == r){
			tree[now] = pair<int, int>(v, v);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, idx, v, now * 2);
		update(mid + 1, r, idx, v, now * 2 + 1);
		tree[now] = calc(tree[now * 2], tree[now * 2 + 1]);
	}
	pair<int, int> read(int l, int r, int wl, int wr, int now){
		if(l > r || r < wl || l > wr){
			return pair<int, int>(1e9+100, -1e9-100);
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		return calc(read(l, mid, wl, wr, now * 2), read(mid + 1, r, wl, wr, now * 2 + 1));
	}
} seg;

int v[MxN];

void solve(){
	int n, m, o, a, b;
	cin >> n >> m;
	seg.build(1, n, 1);
	for(int i=1; i<=n; ++i){
		v[i] = i;
	}
	while(m--){
		cin >> o >> a >> b;
		a++, b++;
		if(o == 0){
			swap(v[a], v[b]);
			seg.update(1, n, a, v[a], 1);
			seg.update(1, n, b, v[b], 1);
		}
		else{
			pair<int, int> now = seg.read(1, n, a, b, 1);
			cout << (now.first == a && now.second == b ? "YES": "NO") << "\n";
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
