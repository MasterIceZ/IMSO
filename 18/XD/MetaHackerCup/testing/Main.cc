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

unordered_map<char, int> cnt;

inline bool check(char s){
	return (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U');
}

inline void solution(){
	string s;
	cin >> s;
	for(auto x: s){
		cnt[x]++;
	}
	using P = pair<int, char>;
	vector<P> v;
	for(auto x: cnt){
		v.emplace_back(x.second, x.first);
	}
	sort(v.begin(), v.end(), greater<P> ());
	int cnt_vowel = 0, cnt_cons = 0;
	char max_vowel, max_cons;
	for(auto x: v){
		if(check(x.second)){
			if(cnt_vowel == 0){
				max_vowel = x.second;
			}
			cnt_vowel += x.first;
		}
		else{
			if(cnt_cons == 0){
				max_cons = x.second;
			}
			cnt_cons += x.first;
		}
	}
	int remain_vowel = cnt_vowel - cnt[max_vowel];
	int remain_cons = cnt_cons - cnt[max_cons];
	cout << min(2 * remain_vowel + cnt_cons, 2 * remain_cons + cnt_vowel);
	cnt.clear();
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	freopen("output.txt", "w", stdout);
	for(int tt=1; tt<=q; ++tt){
		cout << "Case #" << tt << ": ";
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
