/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: balance
 * ALGO		: Math
 * DATE		: 28 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

ll power[33], qs[33];

void solve(){
	power[0] = 1;
	for(int i=1; i<=20; ++i){
		power[i] = power[i - 1] * 3;
	}
	qs[0] = 1;
	for(int i=1; i<=20; ++i){
		qs[i] = qs[i - 1] + power[i];
	}
	ll n;
	cin >> n;
	ll sum = n, i, t = 0;
	while(1){
		for(i=0; i<20; ++i){
			if(qs[i] + n < power[i + 1]){
				break;
			
			}
		}
		n = abs(n - power[i]);
		t++;
		sum += power[i];
		if(!n){
			break;
		}
	}
	cout << t << " " << sum / 2;
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
