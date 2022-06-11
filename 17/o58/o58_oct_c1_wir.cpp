/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o58_oct_c1_wir
 * ALGO		: Stack
 * DATE		: 29 Jan 2022
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
int a[MxN], power[MxN];
// power[i] means amount of power to be used to walk from $i - 1$ to $i$

void solve(){
	int n, m, pw, opr;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	stack<pair<int, int>> st; // (val, power)
	for(int i=1; i<=n; ++i){
		// find j which a[j] < a[i], j < i
		while(!st.empty() && st.top().first >= a[i]){
			st.pop();
		}
		// if empty -> every block before a[i] are not greater than a[i] or
		// we have punched them already
		if(st.empty()){
			pw = 0;
		}
		else{
			// power to be used from $i - 1$ to $i$
			pw = max(st.top().second, a[i] - st.top().first);
		}
		power[i] = pw;
		st.emplace(a[i], pw);
	}
	dbg(to_vector(power, 1, n));
	sort(power + 1, power + n + 1);
	while(m--){
		cin >> opr;
		cout << n - (upper_bound(power + 1, power + n + 1, opr) - (power + 1)) << "\n";
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
