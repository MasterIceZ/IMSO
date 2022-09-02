/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Knight Tournament
 * ALGO		: Disjoint Set Union
 * DATE		: 20 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int p[300300];

int fr(int u){
	dbg(u, p[u]);
	return u == p[u] ? u: fr(p[u]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		p[i] = i;
	}
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		int ra = fr(a), rb = fr(b);
		if(a == c){
			p[rb] = ra;
		}
		else{
			p[ra] = rb;
		}
	}
	for(int i=1; i<=n; ++i){
		cout << (i == p[i] ? 0: p[i]) << " ";
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
