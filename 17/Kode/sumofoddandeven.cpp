/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sum of Odd and Even
 * ALGO		: Implementation
 * DATE		: 22 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int a[3];

void solve(){
	for(int i=1, x; ; ++i){
		cin >> x;
		if(x == 0){
			break;
		}
		a[i % 2] += x;
	}
	cout << a[0] << " " << a[1];
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
