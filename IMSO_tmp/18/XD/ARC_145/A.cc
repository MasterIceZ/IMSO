/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		: 30 Jul 2022
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

string t;

inline bool palin(string s){
	t = s;
	reverse(t.begin(), t.end());
	return t == s;
}

inline void solution(){
	int n; string s;
	cin >> n >> s;
	if(palin(s)){
		cout << "Yes";
		return ;
	}
	s = " " + s;
	for(int i=1, j=n; i<=n && j >= 1 && i < j; ++i, --j){
		// s[j - 1] + s[j] == 'BA'
		// i++, j--
		if(string(1, s[j - 1]) + string(1, s[j]) == "BA"){
			s[i] = 'A';
			s[i + 1] = 'B';
			i++, j--;
			continue;
		}
		if(string(1, s[i]) + string(1, s[i + 1]) == "AB"){
			s[j] = "A"
		}
		if(s[i] == s[j]){
			continue;
		}
		if(s[j] == 'A'){
			s[i] = 'A';
			s[i + 1] = 'B';
		}
		else if(s[j] == 'B'){
			s[i] = 'A';
			s[i + 1] = 'B';
		}
		else if(s[i] == 'B'){
			s[j - 1] = 'A';
			s[j] = 'B';
		}
		else{
			s[j - 1] = 'A';
			s[j] = 'B';
		}
	}
	string x;
	for(int i=1; i<=n; ++i){
		x += s[i];
	}
	dbg(x);
	cout << (palin(x)? "Yes": "No");
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
