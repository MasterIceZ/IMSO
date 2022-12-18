#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
int d[MxN], l[MxN], v[MxN];
vector<int> e[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q, p = 0, sum = 0, max_p = 0;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> d[i] >> l[i];
		if(d[i] > 0){
			p++;
			e[p].emplace_back(sum);
		}
		else{
			e[p].emplace_back(sum);
			p--;
		}
		sum += l[i];
		max_p = max(max_p, p);
	}
	e[p].emplace_back(sum);
	for(int i=1; i<=max_p; ++i){
		for(int j=0; j<e[i].size(); j+=2){
			int stp = e[i][j], edp = e[i][j + 1];
			v[i] = max(v[i], edp - stp);
		}
	}
	vector<pair<int, int>> query(q);
	for(int i=0; i<q; ++i){
		cin >> query[i].first;
		query[i].second = i;
	}
	sort(query.begin(), query.end());
	vector<int> answer(q);
	int it = 0;
	for(int i=max_p; i>=1; --i){
		while(query[it].first <= v[i] && it < q){
			answer[query[it].second] = i;
			it++;
		}
		if(it == q){
			break;
		}
	}	
	for(int i=0; i<q; ++i){
		cout << answer[i] << "\n";
	}
	return 0;
}
