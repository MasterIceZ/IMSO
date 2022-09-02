#include <bits/stdc++.h>

using namespace std;

#ifndef _DEBUG
#include "obstacle.h"
#endif

vector<vector<int>> dr, ul, dp;
int _N, _M;

void initialize(int N, int M, int Q, std::vector<std::vector<int>>& rowlen, std::vector<std::vector<int>>& collen){
	dr.resize(N + 10, vector<int> (M + 10, 1e9 + 100));
	ul.resize(N + 10, vector<int> (M + 10, 1e9 + 100));
	dp.resize(N + 10, vector<int> (M + 10, 1e9 + 100));

	vector<vector<int>> row(N + 10, vector<int> (M + 10, 0));
	vector<vector<int>> col(N + 10, vector<int> (M + 10, 0));


	for(int i=1; i<=N-1; ++i){
		for(int j=1; j<=M; ++j){
			row[i][j] = collen[i - 1][j - 1];
		}
	}
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M-1; ++j){
			col[i][j] = rowlen[i - 1][j - 1];
		}
	}


	dr[1][0] = dr[0][1] = 0;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=M; ++j){
			dr[i][j] = min(dr[i - 1][j] + row[i - 1][j], dr[i][j - 1] + col[i][j - 1]);
		}
	}
	ul[N + 1][M] = ul[N][M + 1] = 0;
	for(int i=N; i>=1; --i){
		for(int j=M; j>=1; --j){
			ul[i][j] = min(ul[i + 1][j] + row[i][j], ul[i][j + 1] + col[i][j]);
		}
	}
	for(int i=N; i>=1; --i){
		for(int j=M; j>=1; --j){
			dp[i][j] = min(dp[i + 1][j], dr[i][j] + ul[i][j]);
		}
	}
	_N = N;
	_M = M;
}

int ask(int r, int c){
    return ((r >= _N - 1 || c == 0) ? -1: dp[r + 2][c]);
}

#ifdef _DEBUG

int main() {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  vector<vector<int>> rowlen(N, vector<int>(M-1));
  vector<vector<int>> collen(N-1, vector<int>(M));
  for (auto &vec : rowlen) 
    for (auto &v : vec) 
      scanf("%d", &v);
  for (auto &vec : collen) 
    for (auto &v : vec) 
      scanf("%d", &v);
  vector<pair<int, int>> query;
  for (int i = 0; i < Q; ++i) {
    int r, c; scanf("%d %d", &r, &c);
    query.emplace_back(r, c);
  }
  initialize(N, M, Q, rowlen, collen);
  for (auto x : query) {
    printf("%d\n", ask(x.first, x.second));
  }
}
#endif
