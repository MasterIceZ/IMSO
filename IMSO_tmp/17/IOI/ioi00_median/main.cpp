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
#include "device.cpp"
#else
#define dbg(...) 0
#include "device.h"
#endif

using ll = long long;

// GetN()
// Med3(a, b, c) => return median of [a, b, c]
// Answer(x) => return index Median of N numbers

// N = 1500
const int MxN = 1505;
int a[MxN];

void solve(){
	int n = GetN();
	for(int i=1; i<=n; ++i){
		a[i] = i;
	}
	int x = n, y = n - 1, z = n - 2; 
	
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
