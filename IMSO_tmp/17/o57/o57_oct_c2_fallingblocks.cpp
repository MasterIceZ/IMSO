/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o57_oct_c2_fallingblocks
 * ALGO		: Segment Tree, Lazy Propagation
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
	struct Node{
		int l, r;
		int up, down;
	};
	Node tree[MxN * 4];
	int lazy[MxN * 4];
	void update(int l, int r, int wl, int wr, int now){
		if(lazy[now]){
			tree[now].l += lazy[now];
			tree[now].r += lazy[now];
			if(l != r){
				lazy[now * 2] += lazy[now];
				lazy[now * 2 + 1] += lazy[now];
			}
			lazy[now] = 0;
		}
		if(l > r || r < wl || l > wr){
			return ;
		}
		if(wl <= l && r <= wr){
			tree[now].l++;
			tree[now].r++;
			if(l != r){
				lazy[now * 2]++;
				lazy[now * 2 + 1]++;
			}
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, now * 2);
		update(mid + 1, r, wl, wr, now * 2 + 1);
		tree[now].l = tree[now * 2].l;
		tree[now].r = tree[now * 2 + 1].r;
		tree[now].up = tree[now * 2].up + tree[now * 2 + 1].up;
		tree[now].down = tree[now * 2].down + tree[now * 2 + 1].down;
		if(tree[now * 2].r < tree[now * 2 + 1].l){
			tree[now].up++;
		}
		else if(tree[now * 2].r > tree[now * 2 + 1].l){
			tree[now].down++;
		}
	}
	Node read(int l, int r, int wl, int wr, int now){
		if(lazy[now]){
			tree[now].l += lazy[now];
			tree[now].r += lazy[now];
			if(l != r){
				lazy[now * 2] += lazy[now];
				lazy[now * 2 + 1] += lazy[now];
			}
			lazy[now] = 0;
		}
		if(l > r || r < wl || l > wr){
			return {0, 0, (int)1e9 + 100, (int)1e9 + 100};
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		Node cur;
		Node L = read(l, mid, wl, wr, now * 2);
		Node R = read(mid + 1, r, wl, wr, now * 2 + 1);
		if(L.up == 1e9 + 100){
			return R;
		}
		else if(R.up == 1e9 + 100){
			return L;
		}
		cur.up = L.up + R.up;
		cur.down = R.down + L.down;
		cur.l = L.l;
		cur.r = R.r;
		if(L.r < R.l){
			cur.up++;
		}
		else if(L.r > R.l){
			cur.down++;
		}
		return cur;
	}
} seg;

void solve(){
	int n, m, t, a, b, x, y;
	cin >> n >> m;
	while(m--){
		cin >> t;
		if(t == 1){
			cin >> a >> b;
			seg.update(1, n, a, b, 1);
		}
		else if(t == 2){
			cin >> x >> y;
			auto now = seg.read(1, n, x, y, 1);
			cout << now.l << " " << now.r << "\n";
		}
		else{
			cin >> x >> y;
			auto now = seg.read(1, n, x, y, 1);
			cout << now.l << " " << now.r << " "  << now.up << " " << now.down << "\n";
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
	}
	return 0;
}
