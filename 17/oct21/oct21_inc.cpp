/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct21_inc
 * ALGO		: Dynamic Programming
 * DATE		: 20 Dec 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int a[1010];
int dp[1010], p[1010];

void solve(){
	int n, x;
	cin >> n;
	int maxx = 0, maxx_idx = -1;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i] = 1;
		for(int j=1; j<i; ++j){
			if(dp[i] < dp[j] + 1 && a[j] < a[i]){
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
		if(maxx < dp[i]){
			maxx = dp[i];
			maxx_idx = i;
		}
	}
	stack<int> st;
	while(maxx_idx != 0){
		st.push(a[maxx_idx]);
		maxx_idx = p[maxx_idx];
	}
	cout << st.size() << "\n";
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
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
