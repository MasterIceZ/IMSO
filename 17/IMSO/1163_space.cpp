/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Space
 * ALGO		: Brute Force
 * DATE		: 25 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int n;

void rec(string s){
	if(s.size() == n){
		for(int i=n-1; i>=0; --i){
			if(s[i] == '0'){
				cout << s << " " ;
				s[i] = '1';
				cout << s << "\n";
				s[i] = '0';
			}
		}
		return ;
	}
	rec(s + "0");
	rec(s + "1");
}

void solve(){
	cin >> n;
	rec("");
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
