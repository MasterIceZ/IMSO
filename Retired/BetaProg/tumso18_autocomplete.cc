/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Autocomplete
 * ALGO		: Implementation
 * DATE		: 14 Jan 2023
 * */

#include <bits/stdc++.h>
using namespace std;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

vector<vector<string>> in;

int main(){
	ios::sync_with_stdio(false);
	string s, t;
	int it = 0;
	while(getline(cin, s)){
		stringstream ss(s);
		while(getline(ss, t, ' ')){
			if(in.size() == it){
				vector<string> tt = {t};
				in.emplace_back(tt);
			}
			else{
				in[it].emplace_back(t);
			}
		}
	}
	int i = 0;
	for(auto x: in){
		cout << "LINE #" << i << ": ";
		for(auto y: x){
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}
