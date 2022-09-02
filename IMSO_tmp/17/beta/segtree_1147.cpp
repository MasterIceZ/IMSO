/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Segment Tree
 * ALGO		: Square Root Decomposition
 * DATE		: 11 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 300300;
int cluster[600], a[MxN];

void solve(){
	int n, q, x, y;
	char opr;
	cin >> n >> q;
	int sq = sqrt(n);
	while(q--){
		cin >> opr >> x >> y;
		if(opr == 'U'){
			a[x] = y;
			cluster[x / sq] = -1e9 - 100;
			for(int i=x / sq * sq; i <= x / sq * sq + sq; ++i){
				cluster[x / sq] = max(cluster[x / sq], a[i]);
			}
		}
		else{
			int answer = -1e9 - 100;
			for(int i=x; i<=y; ){
				if(i % sq == 0 && i + sq - 1 <= y){
					answer = max(answer, cluster[i / sq]);
					i += sq;
				}
				else{
					answer = max(answer, a[i]);
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
