/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o60_oct_c1_house
 * ALGO		: Segment Tree
 * DATE		: 28 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Node{
	int maxx, l, r, sum;
	Node(int v){
		maxx = max(v, 0);
		l = max(v, 0);
		r = max(v, 0);
		sum = v;
	}
	Node(){
		Node(0);
	}
};

const int MxN = 200200;
int a[MxN];
Node tree[4 * MxN], zero;

Node calc(Node a, Node b){
	Node cur;
	cur.maxx = max({a.maxx, b.maxx, a.r + b.l});
	cur.l = max(a.l, a.sum + b.l);
	cur.r = max(b.r, b.sum + a.r);
	cur.sum = a.sum + b.sum;
	return cur;
}

void build(int l, int r, int now){
	if(l > r){
		return ;
	}
	if(l == r){
		tree[now] = Node(a[l]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, now << 1);
	build(mid + 1, r, (now << 1) | 1);
	tree[now] = calc(tree[now << 1], tree[(now << 1) | 1]);
}

Node read(int l, int r, int wl, int wr, int now){
	if(l > r || l > wr || r < wl){
		return zero;
	}
	if(wl <= l && r <= wr){
		return tree[now];
	}
	int mid = (l + r) >> 1;
	return calc(read(l, mid, wl, wr, now << 1), read(mid + 1, r, wl, wr, (now << 1) | 1));
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	build(1, n, 1);
	while(m--){
		int a, b;
		cin >> a >> b;
		a++, b++;
		cout << read(1, n, a, b, 1).maxx << "\n";
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
