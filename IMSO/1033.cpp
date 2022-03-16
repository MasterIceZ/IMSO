/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Conquerer
 * ALGO		: Implementation
 * DATE		: 17 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

char opr;

pair<int, int> pos[11];
int a[111][111], pts[5];
char s[40040];

bool check(int x, pair<int, int> add){
	pair<int, int> cur = make_pair(pos[x].first + add.first, pos[x].second + add.second);
	for(int i=1; i<=4; ++i){
		if(i == x){
			continue;
		}
		if(pos[i] == cur){
			return false;
		}
	}
	return true;
}

void solve(){
	int n, k;
	cin >> n >> k;
	pos[1] = make_pair(1, n);
	pos[2] = make_pair(n, n);
	pos[3] = make_pair(n, 1);
	pos[4] = make_pair(1, 1);
	a[1][n] = 1;
	a[n][n] = 2;
	a[n][1] = 3;
	a[1][1] = 4;
	for(int i=1; i<=4; ++i){
		for(int j=1; j<=k; ++j){
			cin >> s[j * k + i];
		}
	}
	for(int i=0; i<k; ++i){
		for(int j=1; j<=4; ++j){
			int current = j;
			opr = s[j + i * k];
			if(opr == 'S' && check(current, make_pair(1, 0))){
				pos[current] = make_pair(pos[current].first + 1, pos[current].second);
				a[pos[current].first][pos[current].second] = current;
			}
			else if(opr == 'W' && check(current, make_pair(0, -1))){
				pos[current] = make_pair(pos[current].first, pos[current].second - 1);
				a[pos[current].first][pos[current].second] = current;
			}
			else if(opr == 'E' && check(current, make_pair(0, 1))){
				pos[current] = make_pair(pos[current].first, pos[current].second + 1);
				a[pos[current].first][pos[current].second] = current;
			}
			else if(check(current, make_pair(-1, 0))){
				pos[current] = make_pair(pos[current].first - 1, pos[current].second);
				a[pos[current].first][pos[current].second] = current;
			}
			cerr << "OPERATOR : " << (char)(opr) << " " << pos[current].first << ", " << pos[current].second << "\n";
		}
	}
	bool ok = true;
	for(int i=1; i<=n && ok; ++i){
		for(int j=1; j<=n && ok; ++j){
			if(a[i][j] == 0){
				ok = false;
			}
		}
	}
	if(!ok){
		cout << "No";
		return ;
	}

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			pts[a[i][j]]++;
		}
	}
	int maxx = 0;
	for(int i=1; i<=4; ++i){
		maxx = max(maxx, pts[i]);
	}
	vector<int> v;
	for(int i=1; i<=4; ++i){
		if(pts[i] == maxx){
			v.push_back(i);
		}
	}
	cout << v.size() << " " << maxx << "\n";
	for(auto x: v){
		cout << x << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
