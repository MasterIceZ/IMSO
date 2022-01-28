/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o62_may09_househouse
 * ALGO		: Binary Search, Interactive
 * DATE		: 28 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#include "househouse.h"
#endif

using ll = long long;

int c, m;

inline double ckr(int x){
	double v = 0;
	v += (double)(x - 1);
	for(int i=x; i<=m; ++i){
		v += (double)(x + c - 1) / i;
	}
	return v;
}

int main(){
	househouse_init(c, m);
	int l = 1, r = m + 1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(ckr(mid + 1) > ckr(mid)){
			r = mid;
		}	
		else{
			l = mid + 1;
		}
	}
	for(int i=1; i<=m; ++i){
		if(i == r){
			househouse_pay(c);
		}
		else{
			househouse_pay(1);
		}
	}
	return 0;
}
