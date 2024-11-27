#include "marbletracks.h"
#include <bits/stdc++.h>

using namespace std;
 
int fw[100001], timeto0[100001];
 
void upd (int i) { for (; i < 100001; i+=(i&-i)) ++fw[i]; }
 
int qry (int i) { int res = 0; for (; i; i-=(i&-1)) res+=fw[i]; return res; }
 
std::vector<int> observe(int N, int Q, std::vector<int> v, std::vector<std::tuple<int, int, int>> queries) {
    // timeto0[0] = 1, upd(1);
    // int mx = 0;
    std::vector<int> ans;
    // for (int i = 1; i < N; ++i) timeto0[i] = timeto0[v[i]]+1, mx = std::max(mx, timeto0[i]), upd(timeto0[i]);
    for (int i = 0; i < Q; ++i) {
        int s = std::get<0>(queries[i]);
        // int to = std::get<1>(queries[i]);
        // if (to >= mx) ans.emplace_back(N);
        // else ans.emplace_back(qry(to+1)-qry(to));
    }
    return ans;
    // return {};
}
 
/*
9 3 
0 1 2 3 4 5 3 7 7
0 5 6 
0 0 3
0 10000002 10000002
*/