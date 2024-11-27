// #include <vector>
// #include <cstdio>
// #include "dungeons.h"

// int main() {
//     int _N, _Q, _X, _Y;
//     scanf("%d %d", &_N, &_Q);
//     std::vector<int> _A(_N), _B(_N-1), _res(_Q);
//     for (int i=0; i<_N; i++) scanf("%d", &_A[i]);
//     for (int i=0; i<_N-1; i++) scanf("%d", &_B[i]);
//     init(_N, _Q, _A, _B);
//     for (int i=0; i<_Q; i++) scanf("%d %d", &_X, &_Y), _res[i]=solve(_X, _Y);
//     for (int i=0; i<_Q; i++) printf("%d\n", _res[i]);
// }

#include <vector>
#include <stdio.h>
#include "dungeons.h"

int main(int argc, char* argv[]) {
    int N, Q, X, Y;
    scanf("%d %d", &N, &Q);
    std::vector<int> A(N), B(N-1), res(Q);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    for (int i=0; i<N-1; i++) scanf("%d", &B[i]);
    init(N, Q, A, B);
    for (int i=0; i<Q; i++) scanf("%d %d", &X, &Y), res[i]=solve(X, Y);
    for (int i=0; i<Q; i++) printf("%d\n", res[i]);
}