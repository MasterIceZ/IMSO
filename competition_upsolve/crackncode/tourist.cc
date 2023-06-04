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

struct query_t {
	int o, a, b, c;
};

const int MxN = 100010;
int cnt[MxN], p[MxN], closed[MxN], answer[MxN];
pair<int, int> edge[MxN];
query_t query[MxN];
map<int, int> tourist;

inline void init(int n){
	for(int i=1; i<=n; ++i){
		p[i] = i;
	}
}

int find_root(int u){
	if(u == p[u]){
		return u;
	}
	return p[u] = find_root(p[u]);
}

inline void unite(int u, int v){
	int ru = find_root(u), rv = find_root(v);
	if(ru == rv){
		return ;
	}
	p[ru] = rv;
}

inline void solution(){
	int n, m, k, q, maxx = 0;
	cin >> n >> m >> k >> q;
	for(int i=1, x; i<=k; ++i){
		cin >> x;
		cnt[x]++;
		maxx = max(maxx, x);
	}
	for(int i=1; i<=m; ++i){
		cin >> edge[i].first >> edge[i].second;
	}
	for(int i=1; i<=q; ++i){
		cin >> query[i].o;
		if(query[i].o == 1){
			cin >> query[i].a >> query[i].b >> query[i].c;
		}
		else{
			cin >> query[i].a >> query[i].b;
		}
	}
	for(int i=1; i<=maxx; ++i){
		if(cnt[i] == 0){
			continue;
		}
		tourist[cnt[i]]++;
	}
	for(auto x: tourist){
		init(n);
		for(int i=1; i<=q; ++i){
			if(query[i].o == 1 && query[i].b <= x.first && x.first <= query[i].c){
				closed[query[i].a]++;
			}
		}
		for(int i=1; i<=m; ++i){
			if(closed[i] != 0){
				continue;
			}
			unite(edge[i].first, edge[i].second);
		}
		for(int i=q; i>=1; --i){
			if(query[i].o == 1 && query[i].b <= x.first && x.first <= query[i].c){
				if(--closed[query[i].a] == 0){
					unite(edge[query[i].a].first, edge[query[i].a].second);
				}
			}
			else{
				int ru = find_root(query[i].a), rv = find_root(query[i].b);
				if(ru != rv){
					continue;
				}
				answer[i] = answer[i] + x.second;
			}
		}
	}
	for(int i=1; i<=q; ++i){
		if(query[i].o == 2){
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
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
