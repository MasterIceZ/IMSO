#include <cstdio>
#include "vector"
#include "homework.h"
int main() {
    int N;
    scanf("%d",&N);
    std::vector<std::vector<int>> HW(N,std::vector<int>(4));
    std::vector<std::vector<int>> B(N);
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < 4;j++) {
            scanf("%d",&HW[i][j]);
        }
    }
    for(int i = 0;i < N;i++) {
        int c;
        scanf("%d",&c);
        B[i].resize(c);
        for(int j = 0;j < c;j++) {
            scanf("%d",&B[i][j]);
        }
    }
    // printf("%d\n",homework(N,HW,B));
    int answer = homework(N, HW, B);
    printf("\nanswer = %d\n", answer);
}