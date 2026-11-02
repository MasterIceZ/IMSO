#include "pathpathpathpath.h"

#include <cstdio>
#include <vector>

int main() {
    int N, Q;
    (void)scanf("%d%d", &N, &Q);

    std::vector<int> U(N - 1), V(N - 1);
    for (int i = 0; i < N - 1; i++)
        (void)scanf("%d%d", &U[i], &V[i]);

    std::vector<std::vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int s;
        (void)scanf("%d", &s);
        A[i].resize(s);
        for (int& x : A[i]) (void)scanf("%d", &x);
    }

    std::vector<int> X(Q), Y(Q);
    for (int i = 0; i < Q; i++)
        (void)scanf("%d%d", &X[i], &Y[i]);

    std::vector<int> ans_distinct(Q), ans_mode(Q);
    solve(N, Q, U, V, A, X, Y, ans_distinct, ans_mode);

    for (int i = 0; i < Q; i++)
        printf("%d %d\n", ans_distinct[i], ans_mode[i]);

    return 0;
}
