/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o58_oct_c2_restuarant
 * ALGO		: Minimum Spanning Tree
 * DATE		: 1 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
};

const int MxN = 333;
priority_queue<Edge> pq;
int p[MxN], deg[MxN];

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

void solve(){
	int n, state;
	cin >> n >> state;
	for(int i=1; i<=n; ++i){
		for(int j=1, x; j<=n; ++j){
			cin >> x;
			if(i < j){
				pq.push({i, j, x});
			}
		}
		p[i] = i;
	}
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		deg[now.u]++;
		deg[now.v]++;
		p[ru] = rv;
	}
	for(int i=1; i<=n; ++i){
		if(deg[i] >= 3){
			cout << i << "\n";
			if(state == 2){
				cout << deg[i] << "\n";
			}
			return ;
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
