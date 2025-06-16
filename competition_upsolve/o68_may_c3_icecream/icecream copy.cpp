#include "icecream.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,cnt[15][15][15];
vector<int> p;

void initialize(int N, int Q, vector<int> P) {
    n=N;for (auto s : P) p.push_back(s);
    assert(n<=10);

    int root;
    for (int i=0; i<n; ++i) if (p[i]==-1) root=i;
    
    vector<int> temp;
    for (int i=0; i<n; ++i) if (i!=root) temp.push_back(i);

    do {
        vector<pii> res;
        bool can=true;
        int idx[10]; memset(idx,-1,sizeof(idx));
        idx[root]=0;
        for (int i=0; i<(int)(temp.size()); ++i) {
            idx[temp[i]]=i+1;
            if (idx[p[temp[i]]]==-1) can=false;
            else res.push_back(pii(i+1,idx[p[temp[i]]]));
        }

        if (can) {
            for (auto s : res) ++cnt[temp[s.first-1]][s.first][s.second];
        }

    } while (next_permutation(temp.begin(),temp.end()));
}

ll count_perm(int x, int l1, int r1, int l2, int r2) {
    ll ans=0;
    for (int i=l1; i<=r1; ++i) for (int j=l2; j<=r2; ++j) ans+=cnt[x][i][j];
    return ans;
}