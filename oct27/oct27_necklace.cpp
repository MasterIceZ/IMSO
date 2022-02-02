/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct27_necklace
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

const int MxN = 300300;

int l[MxN], r[MxN], p[MxN];

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		p[i] = i;
		r[i] = i;
	}
	for(int i=1, x, y; i<n; ++i){
		cin >> x >> y;
		int ry = fr(y);
		if(r[ry] == y){
			l[r[ry]] = x;
			r[ry] = r[x];
		}
		else{
			l[r[x]] = l[y];
		}
		p[x] = y;
		l[y] = x;
	}
	int now = fr(1);
	while(now != 0){
		cout << now << " ";
		now = l[now];
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
