#include <bits/stdc++.h>
#include "icecream.h"
using namespace std;
typedef long long ll;

const int MX=5000;
const ll mod=1e9+7;

// dp[i][j] = number of permutations of the tree excluding subtree i and par[i] is at position j
// sum[i][j] = number of permutations of the tree excluding subtree i and par[i] is at position <= j
// per[i][j] = number of permutations of the subtree i excluding subtree j
// perm[i] = number of permutations of the subtree i

int n,root,sz[MX+5],p[MX+5];
ll mem_C[MX+5][MX+5], fac[MX+5];
ll dp[MX+5][MX+5],sum[MX+5][MX+5],per[MX+5][MX+5],di[MX+5],perm[MX+5],mul[MX+5];
vector<int> adj[MX+5];

ll binpow(ll a, ll n) {
    ll ans=1;
    while (n) {
        if (n%2) ans=(ans*a)%mod;
        a=(a*a)%mod;
        n/=2;
    }
    return ans;
}

ll C(int n, int r) {
  if(r<0 || r>n) {
    return 0;
  }
  if(n==0 || r==0 || n==r) {
    return 1;
  }
  if(mem_C[n][r] != -1) {
    return mem_C[n][r];
  }
  return mem_C[n][r] = (C(n - 1, r - 1) + C(n - 1, r)) % mod;
}

void dfs1(int x) {
    di[x]=1;
    sz[x]=1;
    mul[x]=1;
    for (auto s : adj[x]) {
        dfs1(s);
        sz[x]+=sz[s];
        di[x]=di[x]*di[s]%mod;
        mul[x]=mul[x]*mul[s]%mod;
    }

    for (auto s : adj[x]) {
        per[x][s] = fac[sz[x]-sz[s]-1] * di[x] %mod * mul[s] %mod;
    }

    di[x]=di[x]*rev[sz[x]]%mod;
    mul[x]=mul[x]*sz[x]%mod;
    perm[x]=fac[sz[x]]*di[x]%mod;
}

void dfs2(int x) {

    for (auto s : adj[x]) {

        for (int i=1; i<=n; ++i) {
            dp[s][i] = sum[x][i-1] * C(n-sz[s]-i,sz[x]-sz[s]-1) % mod * per[x][s] % mod;
        }

        for (int i=1; i<=n; ++i) {
            sum[s][i] = (dp[s][i] + sum[s][i-1]) % mod;
        }

        dfs2(s);
    }
}

void initialize(int N, int Q, vector<int> P) {
    fac[0]=1;
    for (int i=1; i<=MX; ++i) fac[i]=(fac[i-1]*i)%mod;
    memset(mem_C,-1,sizeof(mem_C));
    
    n=N;
    for (int i=0; i<N; ++i) {
        p[i]=P[i];
        if (P[i]==-1) root=i;
        else adj[P[i]].push_back(i);
    }

    dp[root][0]=1;
    for (int i=0; i<=n; ++i) sum[root][0]=1;

    dfs1(root);
    dfs2(root);
}

ll count_perm(int x, int l1, int r1, int l2, int r2) {
    ++l1; ++l2; ++r1; ++r2;

    assert(p[x]!=-1);
    ll sum_temp[n]; sum_temp[0]=0;
    for (int i=1; i<=n; ++i) {
        sum_temp[i]=(sum_temp[i-1] + dp[x][i] * (l2<=i && i<=r2)) %mod;
    }

    ll ans=0;
    for (int i=l1; i<=r1; ++i) {
        ll temp = sum_temp[i-1] * C(n-i,sz[x]-1) %mod * perm[x] %mod;
        ans=(ans+temp)%mod;
    }

    return ans;
}