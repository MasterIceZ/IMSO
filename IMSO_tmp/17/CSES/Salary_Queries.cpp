/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Salary Queries
 * ALGO		: 
 * DATE		: 6 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

tree<pair<int, int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_nod_update> st;

const int MxN = 200100;
int a[MxN];

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		st.insert({a[i], i});
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
