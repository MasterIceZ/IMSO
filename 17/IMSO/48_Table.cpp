#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Cell{
	int x, y, i, v;
	bool operator < (const Cell& o) const{
		return v > o.v;
	}
};

pair<int, int> a[333][5555];

void solve(){
	int r, c, m, opr, x, y, v;
	cin >> r >> c >> m;
	priority_queue<Cell> pq;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			pq.push({i, j, 0, 0});
		}
	}
	for(int i=1; i<=m; ++i){
		cin >> opr;
		if(opr == 1){
			cin >> x >> y >> v;
			a[x][y] = make_pair(v, i);
			pq.push({x, y, i, v});
		}
		else if(opr == 2){
			cin >> x >> v;
			a[x][0] = make_pair(v, i);
			pq.push({x, 0, i, v});
		}
		else if(opr == 3){
			cin >> x >> y;
			if(a[x][0].second > a[x][y].second){
				cout << a[x][0].first;
			}
			else{
				cout << a[x][y].first;
			}
			cout << endl;
		}
		else{
			while(!pq.empty()){
				Cell now = pq.top();
				if(now.y == 0){
					bool ok = false;
					if(a[now.x][0].second > now.i){
						pq.pop();
						continue;
					}
					for(int j=1; j<=c; ++j){
						if(a[now.x][j].second < now.i){
							ok = true;
							break;
						}
					}
					if(!ok){
						pq.pop();
						continue;
					}
					cout << now.v << endl;
					break;
				}
				else{
					if(a[now.x][now.y].second > now.i || a[now.x][0].second > now.i){
						pq.pop();
						continue;
					}
					cout << now.v << endl;
					break;
				}
			}
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
		cout << endl;
	}
	return 0;
}
