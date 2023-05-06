#include <iostream>
#include <vector>
#include <assert.h>
#include "maxrange.cpp"

int main(){
    static int N, K;
    static std::vector<int> A;
    assert(std::cin >> N >> K);
    A.resize(N);
    for(int i = 0; i < N; i++){
        assert(std::cin >> A[i]);
    }
    std::cout << maxrange(N, K, A);
}
