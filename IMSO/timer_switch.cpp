/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: timerswitch
 * ALGO		: KMP
 * DATE		: 3 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 5e6 + 20;
char p[MxN], t[MxN * 2];
int pi[MxN];

void solve(){
	int n;
	cin >> n >> (p + 1);
	strcpy(t + 1, p + 1);
	strcat(t + 1, p + 1);
	for(int i=2, j=0; i<=n; ++i){
		while(j > 0 && p[i] != p[j + 1]){
			j = pi[j];
		}
		if(p[i] == p[j + 1]){
			j += 1;
		}
		pi[i] = j;
	}
	for(int i=2, j=0; i<=2*n; ++i){
		while(j > 0 && t[i] != p[j + 1]){
			j = pi[j];
		}
		if(p[j + 1] == t[i]){
			j += 1;
		}
		if(j == n){
			cout << i - n;
			return ;
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
