#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 66;
int n, m;
char a[MxN][MxN], b[MxN][MxN];
queue<pair<int, int>> q;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline bool isTree(int x_1, int y_1, int x_2, int y_2){
	bool have_tree = false;
	for(int i=x_1; i<=x_2; ++i){
		for(int j=y_1; j<=y_2; ++j){
			have_tree |= (a[i][j] == 'T');
		}
	}
	return have_tree;
}

inline int countPound(int x_1, int y_1, int x_2, int y_2){
	memcpy(b, a, sizeof b);
	int cnt = 0;
	for(int i=x_1; i<=x_2; ++i){
		for(int j=y_1; j<=y_2; ++j){
			if(b[i][j] == 'P'){
				q.emplace(i, j);
				b[i][j] = 'S';
				while(!q.empty()){
					pair<int, int> now = q.front(); q.pop();
					for(int k=0; k<4; ++k){
						int ii = di[k] + now.first, jj = dj[k] + now.second;
						if(ii < 1 || jj < 1 || ii > n || jj > m){
							continue;
						}
						if(b[ii][jj] != 'P'){
							continue;
						}
						b[ii][jj] = 'S';
						q.emplace(ii, jj);
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> m >> n;	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int max_size = min(n, m), answer = 1e9 + 100;
	for(int sz=max_size; sz>=1; --sz){
		bool ok = false;
		for(int i=sz; i<=n; ++i){
			for(int j=sz; j<=m; ++j){
				if(isTree(i - sz + 1, j - sz + 1, i, j)){
					continue;
				}
				ok = true;
				answer = min(answer, countPound(i - sz + 1, j - sz + 1, i, j));
			}
		}
		if(ok){
			cout << sz * sz << " " << answer << "\n";
			return 0;
		}
	}
	cout << "0 0\n";
	return 0;
}
// icy
