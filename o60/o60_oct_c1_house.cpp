/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o60_oct_c1_house
 * ALGO		: Segment Tree
 * DATE		: 4 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 200020;
int a[MxN], n;

struct SegTree{
	struct Node{
		int maxx, l, r, sum;
		Node(int x=0): maxx(max(x, 0)), l(max(x, 0)), r(max(x, 0)), sum(x) {}
	};
	Node tree[4 * MxN];
	Node merge(Node a, Node b){
		Node res;
		res.maxx = max({a.maxx, b.maxx, a.r + b.l});
		res.l = max(a.l, a.sum + b.l);
		res.r = max(b.r, b.sum + a.r);
		res.sum = a.sum + b.sum;
		return res;
	}
	void build(int l=1, int r=n, int now=1){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[now] = Node(a[l]);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, now << 1);
		build(mid + 1, r, now << 1 | 1);
		tree[now] = merge(tree[now << 1], tree[now << 1 | 1]);
	}
	Node read(int wl, int wr, int l=1, int r=n, int now=1){
		if(l > r || l > wr || r < wl){
			return Node(0);
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		return merge(read(wl, wr, l, mid, now << 1), read(wl, wr, mid + 1, r, now << 1 | 1));
	}
} seg;

void solve(){
	int q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	seg.build();
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << seg.read(a + 1, b + 1).maxx << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
