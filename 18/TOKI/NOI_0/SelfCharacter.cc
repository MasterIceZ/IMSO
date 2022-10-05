/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Self Character
 * ALGO		: 
 * DATE		: 3 Oct 2022
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

const int MxN = 100010;
int n, cnt[33];
string s;
set<char> have_chr;
vector<int> chrs;

inline void solution(){
	cin >> n >> s;
	if(n == 1){
		cout << s;
		return ;
	}
	for(auto x: s){
		cnt[x - 'A' + 1]++;
		have_chr.emplace(x);
	}
	for(auto x: have_chr){
		chrs.emplace_back(x);
	}
	string answer = "";
	char first_chr = chrs[0], second_chr = chrs[1];
	int first_it = 0, second_it = 1;
	answer += to_string(first_chr);
	cnt[first_chr - 'A' + 1]--;
	if(cnt[first_chr - 'A' + 1] == 0){
	}
	for(int i=2; i<=n; ++i){
	}
	cout << answer;
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
