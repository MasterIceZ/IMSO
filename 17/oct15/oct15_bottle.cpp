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

const int MxN = 100100;
pair<int, int> h[MxN];
int b[MxN], p[MxN], broked[MxN];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> h[i].first;
		h[i].second = i;
	}
	sort(h + 1, h + n + 1);
	for(int i=1; i<=n; ++i){
		b[i] = h[i].first;
		p[i] = h[i].second;
	}
	int lf = n;
	for(int i=1, x, answer=0; i<=m; ++i, answer=0){
		cin >> x;
		for(int state=lf; state>=1; --state){
			if(b[state] <= x){
				lf = i;
				break;
			}
			if(broked[p[state]] && broked[p[state]] != i){
				continue;
			}
			if(broked[p[state]] != i){
				answer++;
				broked[p[state]] = i;
			}
			if(p[state] + 1 <= n && broked[p[state] + 1] == 0){
				answer++;
				broked[p[state] + 1] = i;
			}
			if(p[state] - 1 >= 1 && broked[p[state] - 1] == 0){
				answer++;
				broked[p[state] - 1] = i;
			}
		}
		cout << answer << "\n";
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
