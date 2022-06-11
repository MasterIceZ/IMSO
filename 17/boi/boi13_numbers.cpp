/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
	ll l, r, answer = 0;
	cin >> l >> r;
	string s;
	for(ll i=l; i<=r; ++i){
		if(i < 10){
			answer++;
		}
		else{
			bool ok = true;
			s = to_string(i);
			for(int i=1; i<s.size()-1; ++i){
				if(s[i - 1] == s[i + 1]){
					ok = false;
					break;
				}
			}
			for(int i=0; i<s.size()-1; ++i){
				if(s[i] == s[i + 1]){
					ok = false;
					break;
				}
			}
			answer += ok;
		}
	}
	cout << answer;
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
