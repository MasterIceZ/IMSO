#include <cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include "penguin.h"

const int MAX_CALL = 250;

int N, POS;
int CALL_COUNT = 0;
int K = 0;
bool FOUND = false;

bool play(std::vector<int> A) {
    assert(++CALL_COUNT <= MAX_CALL);
    printf("move #%d : ", CALL_COUNT);
    int D;
    assert(scanf("%d", &D) == 1);
    if(D == 1){
        POS++;
    }else{
        POS--;
    }
    assert(1 <= POS && POS <= N);
    int k = (int)A.size();
    assert(1 <= k && k <= N);
    K += k * k * k;
    for(int i = 0; i < k; i++) {
        if(A[i] == POS) {
            return FOUND = true;
        }
    }
    return false;
}

signed main(int argc, const char **argv) {
    assert(scanf("%d%d", &N, &POS) == 2);
    penguin(N);
    if(FOUND) {
        printf("Correct.\n");
        printf("Total Cost : %d\n", K);
    }else{
        printf("Incorrect.\n");
    }
    return 0;
}