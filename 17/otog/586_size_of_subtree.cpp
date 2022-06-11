/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: size of subtree
 * ALGO		: Dynamic Programming on Tree
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

const int MxN = 500050;
vector<int> adj[MxN];
int dp[MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> a >> b;
		a++, b++;
		adj[a].push_back(b);
		adj[b].push_back(a);
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
