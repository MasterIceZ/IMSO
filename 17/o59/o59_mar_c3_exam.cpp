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

const int MxN = 50050;
int a[MxN];
vector<int> c;
struct Query{
	int l, r, idx;
	bool operator < (const Query& o) const{
		return r < o.r;
	}
	Query(int a, int b, int c): l(a), r(b), idx(c) {} 
};
struct MO{
	vector<Query> cluster[230];
	int ch[MxN];
	void compute(vector<int>& answer){
		for(int i=0; i<=225; ++i){
			if(cluster[i].empty()){
				continue;
			}
			sort(cluster[i].begin(), cluster[i].end());
			int stp = cluster[i][0].l;
			int edp = cluster[i][0].l;
			int cnt = 0;
			memset(ch, 0, sizeof ch);
			ch[a[stp]]++;
			for(auto x: cluster[i]){
//				dbg(x.l, x.r, x.idx);
				while(stp < x.l){
					ch[a[stp]]--;
					cnt -= (ch[a[stp]] >= 1);
					stp++;
				}
				dbg(stp, edp, cnt);
				while(stp > x.l){
					stp--;
					ch[a[stp]]++;
					cnt += (ch[a[stp]] >= 2);
				}
				dbg(stp, edp, cnt);
				while(edp < x.r){
					edp++;
					ch[a[edp]]++;
					cnt += (ch[a[edp]] >= 2);
				}
				dbg(stp, edp, cnt);
				dbg(x.idx, cnt);
				answer[x.idx] = cnt;
			}
		}
	}
} sqd;

unordered_map<int, int> mp;

void solve(){
	int n, q;
	cin >> n;
	int sq = sqrt(n);
	int it = 1;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		if(mp[a[i]]){
			a[i] = mp[a[i]];
			continue;
		}
		mp[a[i]] = it;
		a[i] = it++;
	}
	dbg(to_vector(a, 1, n));
	cin >> q;
	for(int i=0, l, h; i<q; ++i){
		cin >> l >> h;
		sqd.cluster[l / sq].emplace_back(l, h, i);
	}
	vector<int> v(q);
	sqd.compute(v);
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
