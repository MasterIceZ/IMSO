/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_oct_c2_pointsoncircle
 * ALGO		: Math
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

const int MxN = 1010;
int cir[MxN][MxN], answer[MxN];

void solve(){
	int n, k, x;
	cin >> n >> k;
	for(int i=1; i<=k; ++i){
		for(int j=1; j<=k; ++j){
			cin >> x;
			cir[i][j] = min(x, n - x);
		}
	}
	answer[1] = 0;
	for(int i=2; i<=k; ++i){
		int Add = cir[1][i];
		int Sub = n - cir[1][i];
		bool ok = true;
		for(int j=2; j<i; ++j){
			if(cir[i][j] != min(abs(Add - answer[j]), abs(n + Add - answer[j])) || answer[j] == Add){
				ok = false;
			}
		}
		if(ok){
			answer[i] = Add;
		}
		else{
			answer[i] = Sub;
		}
	}
	for(int i=1; i<=k; ++i){
		cout << answer[i] << "\n";
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
