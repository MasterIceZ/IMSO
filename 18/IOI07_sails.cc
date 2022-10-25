#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

struct fenwick_tree{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=100000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}	
	int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res = res + tree[idx];
		}
		return res;
	}
} fw;

pair<int, int> a[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1); // sort by h
	for(int i=1; i<=n; ++i){
		if(
	}
	return 0;
}
