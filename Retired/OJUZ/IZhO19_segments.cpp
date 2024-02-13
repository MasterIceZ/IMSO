#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 500050;

template<class T>
struct fenwick{
    int n;
    vector<T> t;
    fenwick(int n=0){init(n);}
    void init(int _n){
        n=_n;
        t.assign(n+1,T{});
    }
    void update(int x,const T &v){
        for(int i=x+1;i<=n;i+=i&-i)t[i]=t[i]+v;
    }
    void update(int l,int r,const T &v){
        update(l,v),update(r+1,-v);
    }
    T query(int x){
        T res{};
        for(int i=x+1;i>0;i-=i&-i)res=res+t[i];
        return res;
    }
    T query(int l,int r){
        return query(r)-query(l-1);
    }
    int find(const T &k){
        int x=0;
        T cur{};
        for(int i=1<<31-__builtin_clz(n);i>0;i>>=1)
            if(x+i<=n&&cur+t[x+i]<k)x+=i,cur=cur+t[x];
        return x;
    }
};

ll a[MxN], pref_sum[MxN], dp[2][MxN];
vector<ll> c;
fenwick<ll> fw[2];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    pref_sum[i] = pref_sum[i - 1] + a[i];
    c.emplace_back(pref_sum[i]);
  }
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(), c.end()) - c.begin());
  fw[0].init(c.size() + 10); fw[1].init(c.size() + 10);
  for(int i=1; i<=n; ++i) {
    int idx = upper_bound(c.begin(), c.end(), pref_sum[i]) - c.begin();
    dp[0][i] = fw[0].query(idx) + 1ll;
    dp[1][i] = fw[1].query(idx) + pref_sum[i];

    idx = upper_bound(c.begin(), c.end(), dp[i] + 
    fw[0].update()
  }
  return 0;
}