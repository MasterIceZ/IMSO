/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: SortLtoR Hard
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

const int MxN = 50050;
int a[MxN];
vector<int> cluster[333], tmp;

void merge(vector<int>& v, vector<int> k){
	tmp.clear();
	int i = 0, j = 0;
	while(i < v.size() && j < k.size() && tmp.size() <= 9){
		if(v[i] < k[j]){
			tmp.push_back(v[i++]);
		}
		else{
			tmp.push_back(k[j++]);
		}
	}
	while(i < v.size() && tmp.size() <= 9){
		tmp.push_back(v[i++]);
	}
	while(j < k.size() && tmp.size() <= 9){
		tmp.push_back(k[j++]);
	}
	v = tmp;
}

void solve(){
	int n, q;
	cin >> n >> q;
	int sq = sqrt(n);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		int it = upper_bound(cluster[i / sq].begin(), cluster[i / sq].end(), a[i]) - cluster[i / sq].begin();
		cluster[i / sq].insert(cluster[i / sq].begin() + it, a[i]);
		dbg(cluster[i / sq], a[i]);
		if(cluster[i / sq].size() > 10){
			cluster[i / sq].pop_back();
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		l++, r++;
		vector<int> res;
		for(int i=l; i<=r; ){
			if(i % sq == 0 && i + sq - 1 <= r){
				merge(res, cluster[i / sq]);
				i += sq;
			}
			else{
				int idx = upper_bound(res.begin(), res.end(), a[i]) - res.begin();
				res.insert(res.begin() + idx, a[i]);
				if(res.size() > 10){
					res.pop_back();
				}
				i += 1;
			}
		}
		for(auto x: res){
			cout << x << " ";
		}
		cout << "\n";
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
