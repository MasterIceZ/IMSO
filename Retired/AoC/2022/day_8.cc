#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

const int dj[] = {-1, 1, 0, 0};
const int di[] = {0, 0, -1, 1};

bool ok[MxN][MxN];
int dp[5][MxN][MxN], a[MxN][MxN];

int main_1(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int n, m;
	n = m = 99;
	for(int i=1; i<=n; ++i){
		string s;
		cin >> s;
		for(int j=1; j<=m; ++j){
			a[i][j] = (s[j - 1] - '0');
		}
	}
	memset(dp, -1, sizeof dp);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[1][i][j] = max(dp[1][i][j - 1], a[i][j]);
		}
		for(int j=m; j>=1; --j){
			dp[2][i][j] = max(dp[2][i][j + 1], a[i][j]);
		}
	}
	for(int j=1; j<=m; ++j){
		for(int i=1; i<=n; ++i){
			dp[3][i][j] = max(dp[3][i - 1][j], a[i][j]);
		}
		for(int i=n; i>=1; --i){
			dp[4][i][j] = max(dp[4][i + 1][j], a[i][j]);
		}
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			for(int k=0; k<4; ++k){
				int ii = di[k] + i;
				int jj = dj[k] + j;
				if(dp[k + 1][ii][jj] < a[i][j]){
					ok[i][j] = true;
				}	
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cnt += ok[i][j];
		}
	}
	cout << cnt;
	return 0;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int n, m;
	n = m = 99;
	for(int i=1; i<=n; ++i){
		string s;
		cin >> s;
		for(int j=1; j<=m; ++j){
			a[i][j] = (s[j - 1] - '0');
		}
	}
	int maxx = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			int w, x, y, z;
			w = x = y = z = 0;
			for(int k=i-1; k>=1; --k){
				w++;
				if(a[i][j] <= a[k][j]){
					break;
				}
			}
			for(int k=i+1; k<=n; ++k){
				x++;
				if(a[i][j] <= a[k][j]){
					break;
				}
			}
			for(int k=j-1; k>=1; --k){
				y++;
				if(a[i][j] <= a[i][k]){
					break;
				}
			}
			for(int k=j+1; k<=m; ++k){
				z++;
				if(a[i][j] <= a[i][k]){
					break;
				}
			}
			maxx = max(maxx, w * x * y * z);
		}
	}
	cout << maxx;
	return 0;
}
