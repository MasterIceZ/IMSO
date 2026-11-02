#include <bits/stdc++.h>

#include "water.h"

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int part, subtask;
  cin >> part >> subtask;

  if (part == 1) {
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> X(K), Y(K), S(K);
    for (int i = 0; i < K; i++) cin >> X[i] >> Y[i] >> S[i];
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) cin >> A[i] >> B[i];

    auto ans = find_water(N, K, M, X, Y, S, A, B);
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
      cout << x << ' ' << y << '\n';
    }
  } else {
    int N, K;
    cin >> N >> K;
    vector<int> X(K), Y(K), S(K);
    for (int i = 0; i < K; i++) cin >> X[i] >> Y[i] >> S[i];

    auto ans = place_water(N, K, X, Y, S);
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
      cout << x << ' ' << y << '\n';
    }
  }

  return 0;
}
