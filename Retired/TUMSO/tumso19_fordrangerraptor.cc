/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso19_fordrangerraptor
 * ALGO		: Implementation
 * DATE		: 16 Jan 2023
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
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i == 1 || j == 1 || i == n){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << " ";
		for(int j=1; j<=n; ++j){
			if(i == 1 || j == 1 || j == n){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << " ";
		for(int j=1; j<=n; ++j){
			if(i == 1 || j == 1 || i == n || j == n){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << " ";
		for(int j=1; j<=n; ++j){
			if(i == 1 && j == n){
				cout << " ";
			}
			else if(i == 1 || j == 1 || j == n){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << "\n";
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(j == 1){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << " ";
		for(int j=1; j<=n; ++j){
			if(j == 1 || j == n || i == n){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << " ";
		for(int j=1; j<=n; ++j){
			if(j == 1){
				cout << "#";
			}
			else if(i == j){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << " ";
		for(int j=1; j<=n; ++j){
			if(i == n && j == n){
				cout << " ";
			}
			else if(j == 1 || j == n || i == n){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << "\n";
	}
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
