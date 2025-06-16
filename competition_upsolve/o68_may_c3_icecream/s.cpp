#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXN = 5005;
int N, Q;
vector<int> children[MAXN];
int parentArr[MAXN];
int sz[MAXN];
ll dp_sub[MAXN];  // number of heap‐orderings in subtree u
ll fact[MAXN], invfact[MAXN];
ll inv_dp_sub[MAXN];  // modular inverses of dp_sub[u]
ll dp_total;          // total heap‐orderings of the whole tree
ll M = 1000000007;

// fast exponentiation
ll modpow(ll a, ll e = M - 2) {
  ll r = 1;
  while (e) {
    if (e & 1) r = (r * a) % M;
    a = (a * a) % M;
    e >>= 1;
  }
  return r;
}

// precompute factorials & inv‐factorials
void initFactorials(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % M;
  invfact[n] = modpow(fact[n]);
  for (int i = n; i >= 1; i--) invfact[i - 1] = invfact[i] * i % M;
}

// n choose k
inline ll C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * invfact[k] % M * invfact[n - k] % M;
}

// DFS to compute sz[u] and dp_sub[u]
void dfs(int u) {
  sz[u] = 1;
  ll ways = 1;
  int totalKids = 0;
  for (int v : children[u]) {
    dfs(v);
    // multiply by the number of ways inside child
    ways = ways * dp_sub[v] % M;
    // divide out the child's subtree factorial so we can re‐mix
    // (we'll multiply back once we know the total size)
    ways = ways * invfact[sz[v]] % M;
    totalKids += sz[v];
    sz[u] += sz[v];
  }
  // now multiply by totalKids! to count all interleavings of the
  // children‐blocks
  ways = ways * fact[totalKids] % M;
  dp_sub[u] = ways;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> Q;
  int root = -1;
  for (int i = 0; i < N; i++) {
    cin >> parentArr[i];
    if (parentArr[i] == -1) {
      root = i;
    } else {
      children[parentArr[i]].push_back(i);
    }
  }

  // 1) factorials
  initFactorials(N);

  // 2) subtree DP
  dfs(root);

  // 3) dp_total = total heap‐orderings of entire tree
  //    = N! / product_{v} sz[v]
  // but we already have dp_sub[root] =  ways of mixing its children * ...
  // In fact dp_sub[root] == dp_total, since root has no "parent to divide out".
  dp_total = dp_sub[root];

  // Precompute inv(dp_sub[u]) for all u
  for (int i = 0; i < N; i++) {
    inv_dp_sub[i] = modpow(dp_sub[i]);
  }

  // process queries
  // each query: count_perm(x, l1, r1, l2, r2)
  // we know l1..r1 for x, l2..r2 for p=parentArr[x], and must have p before x
  while (Q--) {
    int x, l1, r1, l2, r2;
    cin >> x >> l1 >> r1 >> l2 >> r2;
    int p = parentArr[x];

    // sizes we need
    int s_c = sz[x];     // size of x‐subtree
    int s_p = sz[p];     // size of p‐subtree
    int k1 = s_c - 1;    // descendants of x (must all lie *after* x)
    int rest = N - s_p;  // all nodes outside p‐subtree

    // dp_sub[x]      = ways inside x's subtree
    // dp_sub[p]      = ways inside p's entire subtree
    // dp_total       = ways for the whole tree
    // inv_dp_sub[p]  = 1 / dp_sub[p]
    //
    // one shows by counting the forest “outside” p-subtree that
    // dp_outside = (N - s_p)! * dp_total * s_p!  * inv( N! * dp_sub[p] )
    //             = dp_total * C(N - s_p + s_p, N - s_p) * inv_dp_sub[p]
    //             = dp_total * C(N, rest) * inv_dp_sub[p]
    // but C(N, rest) = fact[N] / ( fact[rest] * fact[s_p] )
    // so overall factor for “outside p” is:
    ll dp_outside = dp_total * C(N, rest) % M * inv_dp_sub[p] % M;

    // now we need to sum over all distances d = b−a (1 ≤ d < N)
    // and for each d compute two things:
    //  (1) how many ways to interleave all other nodes if parent p
    //      is at pos a and child x at pos a+d  — call that F(d)
    //  (2) how many (a,b) pairs in our query window satisfy b−a = d
    //
    //  Answer = ∑_{d=1..N-1} F(d) * (#(a,b) pairs with b−a=d and
    //                                    a∈[l2..r2], b∈[l1..r1])
    //
    // One can show (by classifying descendants of x, the other
    // descendants of p, and the rest–of–tree forest) that
    //
    //   F(d)
    //   = dp_sub[x]                              // ways inside x‐subtree
    //     *  dp_sub[p]                           // ways inside p‐subtree
    //     *  dp_outside                         // ways for outside‐forest
    //     *  C(d-1, k1)                         // pick positions for x’s
    //     descendants in the gap (d-1 slots)
    //     *  C(N-d-1, s_p - s_c)               // pick positions for p’s
    //     *other* descendants in the tail
    //
    // (All other nodes—the “rest” forest—then fill the remaining slots
    // arbitrarily and contribute exactly dp_outside.)
    //
    // So:
    auto F = [&](int d) -> ll {
      if (d - 1 < k1 || N - d - 1 < (s_p - s_c)) return 0LL;
      ll res = dp_sub[x];
      res = res * dp_sub[p] % M;
      res = res * dp_outside % M;
      res = res * C(d - 1, k1) % M;
      res = res * C(N - d - 1, s_p - s_c) % M;
      return res;
    };

    ll ans = 0;
    // for each possible distance d, count valid (a,b)
    for (int d = 1; d < N; d++) {
      // a ∈ [l2..r2], b = a + d ∈ [l1..r1]
      // ⇒ a ∈ [ max(l2, l1-d)  ..  min(r2, r1-d) ]
      int lo = max(l2, l1 - d);
      int hi = min(r2, r1 - d);
      if (lo <= hi) {
        ll ways_ab = (hi - lo + 1);
        ans = (ans + ways_ab * F(d)) % M;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}