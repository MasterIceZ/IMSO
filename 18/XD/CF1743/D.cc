/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

inline void solution(){
	int n, res = 0;
	cin >> n;
	string s;
	cin >> s;
	for(auto x: s){
		res <<= 1;
		res |= (x - '0');
	}
	int tmp = res, tmp2 = res;
	dbg(res);
	bool found = false;
	for(auto x: s){
		if(x == '0' && found){
			res |= tmp2;
			break;
		}
		else if(x == '1'){
			found = true;
		}
		tmp2 >>= 1;
	}
	dbg(res);
	string r="";
	while(res>0){
		r += to_string((char)((res & 1) + '0'));
		res >>= 1;
	}
	cout << (r == ""?"0": r);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
