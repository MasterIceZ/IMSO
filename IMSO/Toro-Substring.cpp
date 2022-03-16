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

const int MxN = 100100;
int qs[MxN];

void solve(){
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	for(int i=1; i<=n; ++i){
		qs[i] = qs[i - 1] + (s[i] == 'A');
	}
//	cntA = qs[r] - qs[l - 1]
//	cntB = (r - l - 1) - cntA
	for(int i=1, j=n; i<=n && j >= 1 && j <= n; ++i){
		int cntA = qs[j] - qs[i - 1];
		int cntB = (j - i - 1) - cntA;
		while(cntA > cntB){
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
