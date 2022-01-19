/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tiger
 * ALGO		: Implementation
 * DATE		: 18 Jan 2022
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
	int n, m, x, y;
	cin >> n >> m;
	vector<pair<int, int>> fire;
	for(int i=1; i<=n; ++i){
		cin >> x >> y;
		fire.emplace_back(x, y);
	}
	unordered_map<int, int> mp;
	int answer = 0, current = 0;
	for(int i=1; i<=m; ++i){
		cin >> x >> y;
		int min_dist = INT_MAX;
		for(auto a: fire){
			min_dist = min(min_dist, abs(a.first - x) + abs(a.second - y));
		}
		mp[min_dist] += 1;
		if(mp[min_dist] > current){
			answer = min_dist;
			current = mp[min_dist];
		}
	}
	cout << answer ;
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
