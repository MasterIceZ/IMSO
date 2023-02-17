#include "shoes.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
using ll = long long;

struct fenwick_tree{
	ll tree[MxN * 2];
	void update(int idx, ll v){
		for(; idx<MxN * 2; idx+=idx&-idx){
			tree[idx] = tree[idx] + v;
		}
	}
	ll read(int idx){
		ll res = 0ll;
		for(; idx>0; idx-=idx&-idx){
			res = res + tree[idx];
		}
		return res;
	}
} fw;

int a[MxN * 2];
vector<int> pos_1[MxN * 2], pos_2[MxN * 2];

long long count_swaps(std::vector<int> s) {
	int n = s.size();
	for(int i=1; i<=n; ++i){
		a[i] = s[i - 1];
		fw.update(i, 1ll);
	}
	for(int i=n; i>=1; --i){
		if(a[i] < 0){
			pos_2[-a[i]].emplace_back(i);
		}
		else{
			pos_1[a[i]].emplace_back(i);
		}
	}
	ll answer = 0ll;
	for(int i=1; i<=n; ++i){
		if(a[i] < 0){
			a[i] = -a[i];
			if(pos_2[a[i]].back() != i){
				continue;
			}
			int x = pos_1[a[i]].back();
			answer += (fw.read(x) - fw.read(i) - 1ll);
			pos_2[a[i]].pop_back();
			pos_1[a[i]].pop_back();
			fw.update(x, -1);
			fw.update(i, -1);
		}
		else{
			if(pos_1[a[i]].back() != i){
				continue;
			}
			int x = pos_2[a[i]].back();
			answer += (fw.read(x) - fw.read(i));
			pos_2[a[i]].pop_back();
			pos_1[a[i]].pop_back();
			fw.update(x, -1);
			fw.update(i, -1);
		}
	}
	return answer;
}
