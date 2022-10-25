#include <bits/stdc++.h>

using namespace std;

inline void get_next(char now){
	if(now == 'Z'){
		now = 'A';
	}
	else{
		now = now + 1;
	}
}

inline void testcase(){
	int n;
	cin >> n;
	char current_charactor = 'a';
	vector<vector<char>> a = {{'A'}};
	for(int i=1; i<=n; ++i){
		if(i % 4 == 1){
		}
		get_next(&current_charactor);
	}
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		testcase();
	}
	return 0;
}
