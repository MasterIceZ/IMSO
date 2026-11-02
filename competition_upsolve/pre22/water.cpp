#include "water.h"

#include <bits/stdc++.h>

using namespace std;

static const int DX[4] = {-1, 0, 1, 0};
static const int DY[4] = {0, 1, 0, -1};

std::vector<std::pair<int, int>> find_water(
  int N, int K, int M, std::vector<int> X, std::vector<int> Y,
  std::vector<int> S, std::vector<int> A, std::vector<int> B) {
  vector<vector<unsigned char>> blocked(N, vector<unsigned char>(N, 0));
  vector<vector<unsigned char>> water(N, vector<unsigned char>(N, 0));
  vector<vector<int>> cnt(N, vector<int>(N, 0));

  for (int i = 0; i < K; i++) {
    for (int x = X[i]; x < X[i] + S[i]; x++) {
      for (int y = Y[i]; y < Y[i] + S[i]; y++) {
        blocked[x][y] = 1;
      }
    }
  }

  queue<pair<int, int>> q;
  for (int i = 0; i < M; i++) {
    int x = A[i], y = B[i];
    if (!blocked[x][y] && !water[x][y]) {
      water[x][y] = 1;
      q.push({x, y});
    }
  }

  auto inside = [&](int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
  };

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + DX[d], ny = y + DY[d];
      if (!inside(nx, ny) || blocked[nx][ny] || water[nx][ny]) continue;
      cnt[nx][ny]++;
      if (cnt[nx][ny] >= 2) {
        water[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }

  vector<pair<int, int>> ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (water[i][j]) ans.push_back({i, j});
    }
  }
  return ans;
}

std::vector<std::pair<int, int>> place_water(int N, int K, std::vector<int> X,
                                             std::vector<int> Y,
                                             std::vector<int> S) {
  (void)N;
  (void)K;
  (void)X;
  (void)Y;
  (void)S;
  return {};
}
