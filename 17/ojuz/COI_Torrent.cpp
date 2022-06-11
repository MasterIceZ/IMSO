/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: COI_Torrent
 * ALGO		: 
 * DATE		: 10 Jan 2022
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
vector<int> adj[MxN];
int a, b;
vector<int> pth;

bool dfs(int u, int p){
	if(u == b){
		pth.push_back(b);
		return true;
	}
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		if(dfs(x, u)){
			pth.push_back(u);
			return true;
		}
	}
}

void solve(){
	int n;
	cin >> n >> a >> b;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(a, 0);
	reverse(pth.begin(), pth.end());
	int l = 1, r = pth.size();
	while(l < r){
		int mid = (l + r) >> 1;

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
