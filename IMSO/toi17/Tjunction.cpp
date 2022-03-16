/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: T-Junction City
 * ALGO		: Binary Search, Depth First Search
 * DATE		: 23 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 80800;
vector<pair<int, int>> adj[MxN];
int in[MxN], a[MxN], name[MxN];
queue<int> q;
bitset<MxN> visited;

void dfs(int u, int p){
	q.push(u);
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dfs(x.first, u);
	}
}

void solve(){
	int n, u, v, w;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		in[u]++, in[v]++;
	}
	for(int i=0; i<=n; ++i){
		if(in[i] == 1){
			dfs(i, -1);
			break;
		}
	}
	bool ok = false;
	int it = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		name[now] = ++it;
		visited[now] = true;
		for(auto x: adj[now]){
			if(visited[x.first]){
				continue;
			}
			a[it] = x.second;
		}
	}
	int l = 1, r = 1e9 + 10;
	while(l < r){
		dbg(l, r);
		int mid = (l + r + 1) >> 1;
		int cnt = 0, sum = 0;
		for(int i=1; i<=n; ++i){
			sum += a[i];
			if(sum >= mid){
				cnt++;
				sum = 0;
			}
		}
		if(cnt >= 3){
			l = mid ;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l;
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
