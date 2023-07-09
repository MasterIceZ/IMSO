/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 50050;
const int MxM = 100010;
const int MxQ = 100010;
const int SqQ = 1010;

struct query_t {
	int t, x, y;
	query_t(int _t, int _x, int _y):
		t(_t), x(_x), y(_y) {}
	query_t():
		t(-1), x(-1), y(-1) {}
};

int parent[MxN], sz[MxN], u[MxM], v[MxM], w[MxM], answer[MxQ];
query_t query[MxQ];
vector<int> process[SqQ], update_query, read_query, line;
bitset<MxN> update;
stack<int> operations;

bool compareReadQuery(int a, int b) {
	return query[a].y > query[b].y;
}

bool compareWeight(int a, int b) {
	return w[a] > w[b];
}

int find_root(int u) {
	while(u != parent[u]) {
		u = parent[u];
	}
	return u;
}

void unite(int a, int b) {
	int ra = find_root(a), rb = find_root(b);
	if(ra == rb) {
		return ;
	}
	if(sz[ra] > sz[rb]) {
		parent[rb] = ra;
		sz[ra] += sz[rb];
		operations.emplace(rb);
	}
	else {
		parent[ra] = rb;
		sz[rb] += sz[ra];
		operations.emplace(ra);
	}
}

inline void solution(){
	int n, m, q;
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		cin >> u[i] >> v[i] >> w[i];
	}
	cin >> q;
	for(int i=1; i<=q; ++i) {
		cin >> query[i].t >> query[i].x >> query[i].y;
	}
	for(int l=1; l<=q; l+=SqQ) {
		int r = min(q, l + SqQ - 1);
		for(int i=1; i<=n; ++i) {
			parent[i] = i;
			sz[i] = 1;
		}
		update = 0;
		update_query.clear();
		read_query.clear();
		line.clear();
		
		for(int i=l; i<=r; ++i) {
			if(query[i].t == 1) {
				update_query.emplace_back(i);
				update[query[i].x] = true;
			}
			else {
				read_query.emplace_back(i);
			}
		}
		for(int i=1; i<=m; ++i) {
			if(update[i]) {
				continue;
			}
			line.emplace_back(i);
		}
		for(int i=l; i<=r; ++i) {
			if(query[i].t == 1) {
				w[query[i].x] = query[i].y;
			}
			else {
				process[i - l].clear();
				for(auto x: update_query) {
					if(w[query[x].x] < query[i].y) {
						continue;
					}
					process[i - l].emplace_back(x);
				}
			}
		}
		sort(read_query.begin(), read_query.end(), compareReadQuery);
		sort(line.begin(), line.end(), compareWeight);
		int pt = 0;
		for(auto x: read_query) {
			int idx = query[x].x, val = query[x].y;
			while(pt < (int) line.size() && w[line[pt]] >= val) {
				unite(u[line[pt]], v[line[pt]]);
				pt++;
			}
			int cnt_rollback = operations.size();
			for(auto merging: process[x - l]) {
				unite(u[query[merging].x], v[query[merging].y]);
			}
			answer[x] = sz[find_root(idx)];
			while(!operations.empty() && (int) operations.size() > cnt_rollback) {
				int cur = operations.top(); operations.pop();
				sz[parent[cur]] -= sz[cur];
				parent[cur] = cur;
			}
		}
	}
	for(int i=1; i<=q; ++i) {
		if(query[i].t == 2) {
			cout << answer[i] << "\n";
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		//cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
