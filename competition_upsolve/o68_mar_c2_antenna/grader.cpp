#include <iostream>
#include <vector>

#include "antenna.h"

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> A(N);
  for(int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  int Q;
  scanf("%d", &Q);
  std::vector<int> S(Q), K(Q);
  for(int i=0; i<Q; i++) {
    scanf("%d %d", &S[i], &K[i]);
  }
  std::vector<long long> X = transfer_problem(N, Q, A, S, K);
  for(int i=0; i<Q; i++) {
    printf("%lld\n", X[i]);
  }
  return 0;
}
/*
6
5 1 10 2 8 6
30
0 1
0 2
0 3
0 4
0 5
1 1
1 2
1 3
1 4
1 5
2 1
2 2
2 3
2 4
2 5
3 1
3 2
3 3
3 4
3 5
4 1
4 2
4 3
4 4
4 5
5 1
5 2
5 3
5 4
5 5
*/