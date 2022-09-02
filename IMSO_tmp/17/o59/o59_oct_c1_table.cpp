/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_oct_c1_table
 * ALGO		: Lazy Segment Tree
 * DATE		: 4 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxR = 303, MxC = 5005;
int tree[MxR * MxC * 4];
bool lazy[MxR * MxC * 4];

void lzy(int now){
	if(lazy[now]){
		lazy[now * 2] = lazy[now];
		lazy[now * 2 + 1] = lazy[now * 2 + 1];
		tree[now * 2] = tree[now];
		tree[now * 2 + 1] = tree[now];
		lazy[now] = false;
	}
}

void update(int l, int r, int wl, int wr, int v, int now){
	if(l > r || wr < l || wl > r){
		return ;
	}
	if(wl <= l && r <= wr){
		tree[now] = v;
		lazy[now] = true;
		return ;
	}
	lzy(now);
	int mid = (l + r) >> 1;
	update(l, mid, wl, wr, v, now * 2);
	update(mid + 1, r, wl, wr, v, now * 2 + 1);
	tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
}

int Read(int l, int r, int wl, int wr, int now){
	if(l > r || r < wl || l > wr){
		return 1e9 + 100;
	}	
	if(wl <= l && r <= wr){
		return tree[now];
	}
	lzy(now);
	int mid = (l + r) >> 1;
	return min(Read(l, mid, wl, wr, now * 2), Read(mid + 1, r, wl, wr, now * 2 + 1));
}

void solve(){
	int n, m, q, k, x, y, a;
	cin >> n >> m >> q;
	int N = n * m;
	while(q--){
		cin >> k;
		if(k == 1){
			cin >> x >> y >> a;
			int id = (m * (x - 1)) + y;
			update(1, N, id, id, a, 1);
		}
		else if(k == 2){
			cin >> x >> a;
			int l = (x - 1) * m + 1;
			int r = x * m;
			update(1, N, l, r, a, 1);
		}
		else if(k == 3){
			cin >> x >> y;
			int id = (x - 1) * m + y;
			cout << Read(1, N, id, id, 1) << "\n";
		}
		else{
			cout << Read(1, N, 1, N, 1) << "\n";
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
