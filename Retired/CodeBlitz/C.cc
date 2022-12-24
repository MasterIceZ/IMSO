/*
 * AUTHOR    : Hydrolyzed~
 * SCHOOL    : RYW
 * TASK        :
 * ALGO        :
 * DATE        :
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

const ll MOD = 1e9 + 7;
const int MxN = 1010;

struct State{
    int v;
    ll w;
    bool operator < (const State& o) const {
        return w > o.w;
    }
    State(int _v, ll _w):
        v(_v), w(_w) {}
};

vector<pair<int, ll>> adj[MxN];
ll t[MxN], w, d[MxN], answer = 1ll, dd[MxN][MxN];
int u, v, from[MxN];
bitset<MxN> vst;
priority_queue<State> pq;

inline void dijkstra(int start){
    memset(d, 0x3f, sizeof d);
    pq.emplace(start, d[start] = 0ll);
    while(!pq.empty()){
        State now = pq.top(); pq.pop();
        for(auto x: adj[now.v]){
            ll nxt = now.w + x.second;
            if(d[x.first] > nxt){
                pq.emplace(x.first, d[x.first] = nxt);
            }
        }
    }
}

inline ll solveCountry(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dijkstra(1);
    for(int i=1; i<=n; ++i){
        adj[i].clear();
    }
    return d[n] * 2ll;
}

void dfs(int u, int p){
	vst[u] = true;
	for(auto x: adj[u]){
		if(x.first == p || vst[x.first]){
			continue;
		}
		from[u] = x.first;
		dfs(x.first, u);
	}
}

inline void solution(){
    int c, s;
    cin >> c;
    for(int i=1; i<=c; ++i){
        t[i] = (solveCountry() % MOD);
    }
    dbg(to_string(t, 1, c));
    cin >> s;
    for(int i=2; i<=c; ++i){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
		dd[u][v] = dd[v][u] = w * 2ll;
    }
	for(int i=1; i<=n; ++i){
		
	}
	cout << answer;
    return ;
}

signed main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);    
    int q = 1;
//    cin >> q;
    while(q--){
        solution();
        cout << "\n";
    }
    return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template

