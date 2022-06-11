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

const int MxN = 200200;
int a[MxN], b[MxN];

void solve(){
	int n, r = -1;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		r = max(r, a[i]);
	}
	
	auto check = [] (int mid, int n){
		memcpy(b, a, sizeof a);
		for(int i=n; i>=3; --i){
			if(b[i] < mid){
				return false;
			}
			int cur = min(b[i], (b[i] - mid)) / 3;
			b[i - 1] += cur;
			b[i - 2] += cur * 2;
		}	
		return b[1] >= mid && b[2] >= mid;
	};

	int l = 1;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid, n)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l;
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
