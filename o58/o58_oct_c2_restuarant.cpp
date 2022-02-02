/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 333;
priority_queue<Edge> pq;
int p[MxN], deg[MxN];

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

void solve(){
	int n, m, x;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> x;
			if(i > j){
				pq.emplace(i, j, x);
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
			if(m == 2){
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
	}
	return 0;
}
