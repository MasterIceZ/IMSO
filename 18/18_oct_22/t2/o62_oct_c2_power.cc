#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MxN = 200020;
ll a[MxN];

struct segment_tree{
	ll tree[MxN << 2];
	ll merge(ll a, ll b){
		return max(a, b);
	}
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[idx] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
	void update(int l, int r, int id, ll v, int idx){
		if(l > r || l > id || r < id){
			return ;
		}
		if(l == r){
			tree[idx] = max(tree[idx], v);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
	}
	ll read(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return LLONG_MIN;
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return merge(read(l, mid, wl, wr, idx << 1), read(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} up, down;

int main(){
	int n, m;
	ll maxx = 0ll;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		a[i] = (ll) i;
	}
	up.build(1, n, 1);
	for(int i=1; i<=n; ++i){
		a[i] = -a[i];
	}
	down.build(1, n, 1);
	for(int i=1; i<=m; ++i){
		ll a, b, c;
		cin >> a >> b >> c;
		ll update_v1 = max(up.read(1, n, 1, a, 1) - a, down.read(1, n, a, n, 1) + a) + c;
		ll update_v2 = max(up.read(1, n, 1, b, 1) - b, down.read(1, n, b, n, 1) + b) + c;
		maxx = max({maxx, update_v1, update_v2});
		cout << maxx << "\n";
		up.update(1, n, b, update_v1 + b, 1); down.update(1, n, b, update_v1 - b, 1);
		up.update(1, n, a, update_v2 + a, 1); down.update(1, n, a, update_v2 - a, 1);
	}
	return 0;
}
