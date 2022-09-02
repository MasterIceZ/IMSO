/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tiling
 * ALGO		: Divide and Conquer
 * DATE		: 20 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

vector<tuple<int, int, int>> answer;

void divide(int n, int midx, int midy, int x, int y){
	int t;
	if(x < midx && y < midy){
		type = 0;
	}
	else if(x < midx && y >= midy){
		type = 1;
	}
	else if(x >= midx && y < midy){
		type = 2;
	}
	else{
		type = 3;
	}
	answer.emplace_back(type, midy - 1, midx - 1);
	if(n <= 2){
		return ;
	}
	if(type == 0){
		divide(n / 2, midx - n / 4, midy - n / 4, x, y);
	}
	else{
		divide(n / 2, midx - n / 4, mid - n / 4, midx - 1, midy - 1);
	}
	
}

void solve(){
	int l, holex, holey;
	cin >> l >> holex >> holey;
	divide(n, n/2, n/2, holey, holex);
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
