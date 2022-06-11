/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Circular RMQ
 * ALGO		: Segment Tree
 * DATE		: 29 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 200200;
ll tree[MxN * 4], a[MxN], lazy[MxN * 4], v;

void build(int l, int r, int now){
	if(l > r){
		return ;
	}
	if(l == r){
		tree[now] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, now * 2);
	build(mid + 1, r, now * 2 + 1);
	tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
}

void lzy(int idx){
	if(lazy[idx]){
		lazy[idx * 2] += lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
		tree[idx * 2] += lazy[idx];
		tree[idx * 2 + 1] += lazy[idx];
		lazy[idx] = 0;
	}
}

void update(int l, int r, int wl, int wr, int val, int now){
	if(l > r || r < wl || l > wr){
		return ;
	}
	if(wl <= l && r <= wr){
		tree[now] += val;
		lazy[now] += val;
		return ;
	}
	lzy(now);
	int mid = (l + r) >> 1;
	update(l, mid, wl, wr, val, now * 2);
	update(mid + 1,  r, wl, wr, val, now * 2 + 1);
	tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
}

ll read_range(int l, int r, int wl, int wr, int now){
	if(l > r || l > wr || r < wl){
		return LLONG_MAX;
	}
	if(wl <= l && r <= wr){
		return tree[now];
	}
	lzy(now);
	int mid = (l + r) >> 1;
	return min(read_range(l, mid, wl, wr, now * 2), read_range(mid + 1, r, wl, wr, now * 2 + 1));
}

void solve(){
	int n, q, l, r;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	build(1, n, 1);
	cin >> q;
	cin.ignore();
	while(q--){
		string s;
		getline(cin, s);
		istringstream ss(s);
		ll x;
		vector<ll> v;
		while(ss >> x){
			v.push_back(x);
		}
		dbg(v);
		if(v.size() == 2){
			l = v[0] + 1, r = v[1] + 1;
			if(l <= r){
				cout << read_range(1, n, l, r, 1);
			}
			else{
				ll q1 = read_range(1, n, l, n, 1);
				ll q2 = read_range(1, n, 1, r, 1);
				cout << min(q1, q2);
			}
			cout << "\n";
		}
		else if(v.size() == 3){
			l = v[0] + 1, r = v[1] + 1, x = v[2];
			if(l <= r){
				update(1, n, l, r, x, 1);
			}
			else{
				update(1, n, l, n, x, 1);
				update(1, n, 1, r, x, 1);
			}
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
