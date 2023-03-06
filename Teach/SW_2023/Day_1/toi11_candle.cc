#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 2020;
char a[MxN][MxN];
queue<pair<int, int>> q;

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '1'){
				cerr << "D : (" << i << ", " << j << ")\n";
				q.emplace(i, j);
				a[i][j] = '0';
				while(!q.empty()){
					pair<int, int> now = q.front(); q.pop();
					for(int k=0; k<8; ++k){
						int ii = di[k] + now.first, jj = dj[k] + now.second;
						if(ii < 1 || jj < 1 || ii > n || jj > m){
							continue;
						}
						if(a[ii][jj] == '1'){
							q.emplace(ii, jj);
							a[ii][jj] = '0';
						}
					}
				}
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
// icy
