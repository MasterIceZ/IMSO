#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MxN = 1000010;
ll v[MxN], s[MxN];
int label[MxN], p[MxN];

int fr(int u){
	return u == p[u] ? u: p[u] = fr(p[u]);
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int c, g, m;
	cin >> c >> g >> m;
	for(int i=1; i<=g; ++i){
		cin >> v[i];
		p[i] = i;
	}
	for(int i=1, x, y; i<=m; ++i){
		cin >> x >> y;
		int ry = fr(y);
		if(ry == y){
			label[y] = x;
			s[x] += y;
		}
		else{
			label[ry] = 
			p[x] = ;
		}
	}
	return 0;
}
