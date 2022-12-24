#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 1010;
const int MOD = 1e9 + 7;
ll dp[MxN][5];

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    dp[1] = 0; dp[2] = 4; dp[3] = 8;
    for(int i=4; i<=n; ++i){
        dp[i] = dp[i - 2] * dp[i - ]
    }
    return 0;
}
