/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o58_oct_c1_wir
 * ALGO		: Stack
 * DATE		: 19 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;
int a[MxN];
stack<pair<int, int>> st;

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, x, power; i<=n; ++i){
		cin >> x;
		while(!st.empty() && st.top().first >= x){
			st.pop();
		}
		if(st.empty()){
			power = 0;
		}
		else{
			power = max(st.top().second, x - st.top().first);
		}
		a[i] = power;
		st.emplace(x, power);
	}
	sort(a + 1, a + n + 1);
	while(m--){
		int x;
		cin >> x;
		cout << n - (upper_bound(a + 1, a + n + 1, x) - (a + 1)) << "\n";
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
