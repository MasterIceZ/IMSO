#include <bits/stdc++.h>
#include "orgdelivery.h"

using namespace std;
using ll = long  long;

const int MxN = 100010;

struct segment_tree {
	ll t[MxN << 2];

	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = 1e18 + 100ll;
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = min(t[idx << 1], t[idx << 1 | 1]);
	}

	void update(int l, int r, int id, ll v, int idx) {
		if(l > r || r < id || l > id) {
			return ;
		}
		if(l == r) {
			t[idx] = v;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		t[idx] = min(t[idx << 1], t[idx << 1 | 1]);
	}
	
	ll query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return 1e18 + 100ll;
		}
		if(wl <= l && r <= wr) {
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return min(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
};

segment_tree seg;
vector<pair<int, ll>> adj[MxN];
vector<pair<ll, int>> queries, v;
int timer, tin[MxN], tout[MxN];
ll dist[MxN];

void dfs(int u) {
	tin[u] = ++timer;
	for(auto x: adj[u]) {
		dist[x.first] = dist[u] + x.second;
		dfs(x.first);
	}
	tout[u] = timer;
}

vector<ll> mincost(int N, vector<int> P, vector<ll> V, vector<int> W, int Q, vector<int> A, vector<int> B) {
	for(int i=1; i<N; ++i) {
		int u = P[i], v = i;
		adj[u].emplace_back(v, W[i]);
	}
	for(int i=0; i<N; ++i) {
		v.emplace_back(V[i], i);
	}
	for(int i=0; i<Q; ++i) {
		queries.emplace_back(V[A[i]], i);
	}

	dfs(0);
	seg.build(1, N, 1);
	sort(v.begin(), v.end());
	sort(queries.begin(), queries.end());

	int it = 0;
	vector<ll> answer(Q, 1e18 + 100ll);

	for(auto query: queries) {
		while(it < N && v[it].first <= query.first) {
			int idx_upd = tin[v[it].second];
			ll val_upd = dist[v[it].second] - v[it].first;
			seg.update(1, N, idx_upd, val_upd, 1);
			it++;
		}
		answer[query.second] = min(answer[query.second], seg.query(1, N, tin[B[query.second]], tout[B[query.second]], 1) + query.first - dist[B[query.second]]);
	}	

	seg.build(1, N, 1);
	reverse(v.begin(), v.end());
	reverse(queries.begin(), queries.end());

	it = 0;

	for(auto query: queries) {
		while(it < N && v[it].first >= query.first) {
			int idx_upd = tin[v[it].second];
			ll val_upd = dist[v[it].second] + v[it].first;
			seg.update(1, N, idx_upd, val_upd, 1);
			it++;
		}
		answer[query.second] = min(answer[query.second], seg.query(1, N, tin[B[query.second]], tout[B[query.second]], 1) - query.first - dist[B[query.second]]);
	}	

	return answer;
}
