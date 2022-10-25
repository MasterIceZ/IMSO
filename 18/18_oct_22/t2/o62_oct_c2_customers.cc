#include <bits/stdc++.h>

using namespace std;

using ll = int;
const int MxN = 120020 << 1;
const int SQ = 490;
vector<int> shop[MxN], customer[MxN];
ll customer_money[MxN], shop_money[MxN], last[MxN];
bool big[MxN];

int main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
//	cin >> n >> m >> q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i=1, l; i<=m; ++i){
//		cin >> l;
		scanf("%d", &l);
		for(int j=1, x; j<=l; ++j){
//			cin >> x;
			scanf("%d", &x);
			if(l <= SQ){
				big[i] = true;
				shop[i].emplace_back(x);
			}
			else{
				customer[x].emplace_back(i);
			}
		}
	}
	while(q--){
		int t;
//		cin >> t;
		scanf("%d", &t);
		if(t == 1){
			int x;
			ll y;
//			cin >> x >> y;
			scanf("%d %d", &x, &y);
			ll more = y - last[x];
			if(big[x]){
				for(auto a: shop[x]){
					customer_money[a] += more;
				}
			}
			last[x] = y;
		}
		else{
			int x;
//			cin >> x;
			scanf("%d", &x);
			ll res = customer_money[x];
			for(auto a: customer[x]){
				res = res + last[a];
			}
//			cout << res << "\n";
			printf("%d\n", res);
		}

	}
	return 0;
}
