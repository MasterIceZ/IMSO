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
string t;
vector<string> res, now;
unordered_map<string, string> last;

vector<string> stringParser(string s){
	stringstream ss(s);
	res.clear();
	while(getline(ss, t, ' ')){
		res.emplace_back(t);
	}
	return res;
}

inline void solution(){
	getline(cin, t);
	int n = stoll(t);
	dbg(n);
	string s, current = "root";
	last["root"] = "root";
	for(int i=1; i<=n; ++i){
		getline(cin, s);
		now = stringParser(s);
		if(s == "pwd"){
			cout << current << "\n";
		}
		else if(s == "cd ."){
			continue;
		}
		else if(s == "cd .."){
			current = last[current];
		}
		else if(now[0] == "cd" && now.size() == 2){
			last[now[1]] = current;
			current = now[1];
		}
		else{
			cout << "ClitzBode is invaded!\n";
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		//cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
