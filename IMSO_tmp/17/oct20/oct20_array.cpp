/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct20_array
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

struct QRY{
	int type, a, b;
	ll v;
};

const int MxN = 200200;
vector<int> cp;

struct Segment_Tree{
	ll tree[MxN * 4], lazy[MxN * 4];
	void update(int l, int r, int wl, int wr, ll v, int now){
		if(lazy[now]){
			tree[now] += lazy[now * 2] * (cp[r+1] - cp[l]);
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
			tree[now] += v * (cp[r+1] - cp[l]);
			if(l != r){
				lazy[now * 2] += v;
				lazy[now * 2 + 1] += v;
			}
			dbg(tree[now]);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, v, now * 2);
		update(mid + 1, r, wl, wr, v, now * 2 + 1);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
	
	ll read(int l, int r, int wl, int wr, int now){
		if(lazy[now]){
			tree[now] += lazy[now] * (cp[r+1] - cp[l]);
			if(l != r){
				lazy[now * 2] += lazy[now];
				lazy[now * 2 + 1] += lazy[now];
			}
			lazy[now] = 0;
		}

		if(l > r || wl > r || wr < l){
			return 0;
		}
		if(wl <= l && r <= wr){
			dbg(now);
			return tree[now];
		}
		int mid = (l + r) >> 1;
		return read(l, mid, wl, wr, now * 2) + read(mid + 1, r, wl, wr, now * 2 + 1);
	}
} seg;

void solve(){
	int n, m, a, b, c;
	ll d;
	cin >> n >> m;
	vector<QRY> query;
	cp.push_back(0);
	cp.push_back(n);
	for(int i=1; i<=m; ++i){
		cin >> a >> b >> c ;
		cp.push_back(b);
		cp.push_back(c);
		if(a == 1){
			query.push_back({a, b, c, 0});
		}
		else{
			cin >> d;
			query.push_back({a, b, c, d});
		}
	}
	sort(cp.begin(), cp.end());
	cp.resize(unique(cp.begin(), cp.end()) - cp.begin());
	for(auto x: query){
		int a = lower_bound(cp.begin(), cp.end(), x.a) - cp.begin();
		int b = lower_bound(cp.begin(), cp.end(), x.b) - cp.begin() - 1;
		if(x.type == 1){
			cout << seg.read(0, cp.size() - 2, a, b, 1) << "\n";
		}
		else{
			seg.update(0, cp.size() - 2, a, b, x.v, 1);
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
