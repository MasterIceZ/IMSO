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
#else
#define dbg(...) 0
#endif

using ll = long long;

void solve(){
	string s;
	cin >> s;
	int a = 0, b = 0, i = 0;
	while(s[i] != '/'){
		a *= 10;
		a += s[i] - '0';
	}
	i++;
	while(i != s.size()){
		b *= 10;
		b += s[i] - '0';
	}
	while(a != 1 && b != 1){
		int tmp = a, tmp2 = b;
		if(a > b){
			a = tmp2;
			b = tmp - tmp2;
			cout << "R";
		}
		else{
			b = tmp;
			a = tmp2 - tmp;
			cout << "L";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
