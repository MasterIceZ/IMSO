#include <bits/stdc++.h>
 
using namespace std;
 
signed main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    while(t--) {
        char s[4];
        int cnt[3] = {0, 0, 0};
        for(int i=0; i<3; ++i) {
            scanf(" %s", s);
            for(int j=0; j<3; ++j) {
                if(s[j] == '?') {
                    continue;
                }
                cnt[s[j] - 'A']++;   
            }
        }
        if(cnt[0] == 2) {
            printf("A");
        }
        else if(cnt[1] == 2) {
            printf("B");
        }
        else {
            printf("C");
        }
        printf("\n");
    }
}
