/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: array
 * ALGO		: Segment Tree, Lazy Propagation
 * DATE		: 5 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	int n, q, a, b, v;
	cin >> n >> q;
	map<int, int> compress;
	vector<QUERY> query;
	for(int i=1; i<=n; ++i){
		cin >> opr;
		if(opr == 0){
			cin >> a >> b >> v;
			mp[a] = 1;
			mp[b] = 1;
			query.push_back({0, a, b, v});
		}
		else{
			cin >> a >> b;
			mp[a] = 1;
			mp[b] = 1;
			query.push_back({1, a, b, 0});
		}
	}
	for(int i=1; i<=n; ++i){
		
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
