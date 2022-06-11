// Credit : https://ideone.com/zZGO5q

/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_prime
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

const int MxN = 1e9;
bitset<MxN / 2> bits;

void solve(){
	int n, cnt = 1;
	cin >> n;
	if(n == 1){
		cout << 2 ;
		return ;
	}
	bits.set();
	for(ll i=3; i/2 < bits.size(); i=2 * bits._Find_next(i / 2) + 1){
		if(++cnt == n){
			cout << i;
			return ;
		}
		for(ll j=i*i/2; j < bits.size(); j+=i){
			bits[j] = false;
		}
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
