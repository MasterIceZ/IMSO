#include "districts.h"
#include <cstdio>
#include <cassert>
#include <vector>

int main(int argc, char** argv){
  int N, M, K;
  assert(scanf("%d %d %d", &N, &M, &K)==3);

  std::vector<int> X(N), Y(N);
  std::vector<int> U(M), V(M);

  for(int i = 0; i < N; i++) {
    assert(scanf("%d %d", &X[i], &Y[i])==2);
  }
  for(int i = 0; i < M; i++){
    assert(scanf("%d %d", &U[i], &V[i])==2);
  }
  // fclose(stdin);

  long long result = divide_districts(N, M, K, X, Y, U, V);

  printf("%lld", result);
  // fclose(stdout);
  return 0;
}
