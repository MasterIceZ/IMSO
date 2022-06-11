/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Airplane Parking
 * ALGO		: Dynamic Programming
 * DATE		: 19 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 303;
pair<int, int> a[MxN];
int dp[2 * MxN][2 * MxN], mem[2 * MxN][2 * MxN];

int divide(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(l + 1 == r){
		return dp[l][r] = mem[l][r];
	}
	int res = -1;
	for(int k=l+1; k<r; ++k){
		res = max(res, divide(l, k) + divide(k, r));
	}
	return dp[l][r] = res + mem[l][r];
}

void solve(){
	memset(dp, -1, sizeof dp);
	memset(mem, 0, sizeof mem);
	int n;
	cin >> n;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
		c.push_back(a[i].first);
		c.push_back(a[i].second);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		int A = lower_bound(c.begin(), c.end(), a[i].first) - c.begin();
		int B = lower_bound(c.begin(), c.end(), a[i].second) - c.begin();
		mem[A][B] = 1;
	}
	cout << divide(0, c.size() - 1);
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
