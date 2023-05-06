#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 200020;
const int MxA = 1000010;
int a[MxN];
ll cnt[MxA];
vector<int> v;

inline ll get_ways(int f, int i){
	int s = i;
	ll t = (ll) s * (s / f);
	if(t > 1000000ll){
		return 0ll;
	}
	if(cnt[f] == 0 || cnt[t] == 0){
		return 0ll;
	}
	ll res = 0ll;
	if(s == t){
		res += (cnt[s] * (cnt[s] - 1ll) * (cnt[s] - 2ll));
	}
	else{
		res += (cnt[f] * cnt[s] * cnt[t]);
	}
	return res;
}

inline void solution(){
	memset(cnt, 0, sizeof cnt);
	int n;
	cin >> n;
	v.clear();
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		cnt[a[i]]++;
		v.emplace_back(a[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	ll ways = 0ll;
	for(auto i: v){
		if(cnt[i] == 0){
			continue;
		}
		int sq = sqrt(i);
		for(int j=1; j<=sq; ++j){
			if(i % j){
				continue;
			}
			if(j * j == i){
				ways += get_ways(j, i);
			}
			else{
				ways += get_ways(j, i);
				ways += get_ways(i / j, i);
			}
		}
	}
	cout << ways;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}

