/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o60_oct_c1_deep
 * ALGO		: Lowest Common Ancestor
 * DATE		: 2 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 200200;

int s, a, b;
int dir(){
	int res = ((s & 8) >> 3);
	s = (s * a + b) % 40507;
	return res;
}

vector<pair<int, int>> edges;
int level[MxN], dp[MxN][22];

void dfs(int u, int lv){
	level[u] = lv;
	if(edges[u].first  == -1 && edges[u].second == -1){
		for(int i=0; i<=17; ++i){
			dp[u][i] = u;
		}
		return ;
	}
	if(edges[u].first != -1 && edges[u].second != -1){
		for(int i=0; i<=17; ++i){
			dp[u][i] = u;
		}
		level[u] = lv + 1;
		dfs(edges[u].first, lv + 1);
		dfs(edges[u].second, lv + 1);
		return ;
	}
	int cur;
	if(edges[u].first == -1){
		cur = edges[u].second;
	}
	else{
		cur = edges[u].first;
	}
	dfs(cur, lv);
	dp[u][0] = cur;
	for(int i=1; i<=17; ++i){
		dp[u][i] = dp[dp[u][i - 1]][i - 1];
	}
}

int calc(int lv, int u){
	dbg(lv, u);
	if(lv == 0){
		return u;
	}
	if(level[dp[u][0]] != level[u]){
		lv--;
		u = dp[u][0];
	}
	while(edges[u].first != -1 && edges[u].second != -1){
		if(lv == 0){
			return u;
		}
		bool state = dir();
		lv--;
		if(state){
			u = edges[u].second;
		}
		else{
			u = edges[u].first;
		}
	}
	for(int i=17; i>=0; --i){
		if(lv - (1 << i) < 0){
			continue;
		}
		if(level[dp[u][i]] != level[u]){
			continue;
		}
		u = dp[u][i];
		lv -= (1 << i);
	}
	return calc(lv, u);
}

void solve(){
	int n, q, u, v, l;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> u >> v;
		edges.emplace_back(u, v);
	}
	dfs(0, 1);
	while(q--){
		cin >> l >> s >> a >> b;
		cout << calc(l, 0);
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
