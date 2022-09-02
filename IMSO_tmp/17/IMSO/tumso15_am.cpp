/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AouheiMaimuenteekuiganwainiwa
 * ALGO		: Implementation
 * DATE		: 29 Dec 2021
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
	int n;
	cin >> n;
	for(int i=1; i<=n - 2; ++i){
		cout << " ";
	}	
	cout << "^ \n";
	for(int i=2; i<=n - 1; ++i){
		for(int j=1; j<=n-1-i; ++j){
			cout << " ";
		}
		cout << "/";
		for(int j=1; j<=2 *(i -1) - 1; ++j){
			cout << " ";
		}
		cout << "\\ \n";
	}
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
