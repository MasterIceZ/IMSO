/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Give Away
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

const int MxN = 500050;
int a[MxN];
vector<int> cluster[777];

void solve(){
	int n;
	cin >> n;
	int sq = sqrt(n);
	for(int i=0; i<n; ++i){
		cin >> a[i];
		cluster[i / sq].push_back(a[i]);
	}
	for(int i=0; i<=sq; ++i){
		sort(cluster[i].begin(), cluster[i].end());
	}
	int q, o, l, r, x, y;
	cin >> q;
	while(q--){
		cin >> o;
		if(o == 1){
			cin >> x >> y;
			x--;
			int id = x / sq;
			cluster[id].erase(lower_bound(cluster[id].begin(), cluster[id].end(), a[x]));
			cluster[id].push_back(y);
			sort(cluster[id].begin(), cluster[id].end());
			a[x] = y;
		}
		else{
			cin >> l >> r >> x;
			l--, r--;
			int answer = 0;
			for(int i=l; i<=r; ){
				if(i % sq == 0 && i + sq <= r){
					int id = i / sq;
					int lb = lower_bound(cluster[id].begin(), cluster[id].end(), x) - cluster[id].begin();
					answer += sq - lb;
					i += sq;
				}
				else{
					answer += (a[i] >= x);
					i += 1;
				}
			}
			cout << answer << "\n";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
