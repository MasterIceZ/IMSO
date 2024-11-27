#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;

template<class T,bool directed=true,bool scaling=true>
struct Dinic{
    static constexpr T INF=numeric_limits<T>::max()/2;
    struct Edge{
        int to;
        T flow,cap;
        Edge(int _to,T _cap):to(_to),flow(0),cap(_cap){}
        T remain(){return cap-flow;}
    };
    int n,s,t;
    T U;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> ptr,lv;
    bool calculated;
    T max_flow;
    Dinic(){}
    Dinic(int n,int s,int t){init(n,s,t);}
    void init(int _n,int _s,int _t){
        n=_n,s=_s,t=_t;
        U=0;
        e.clear();
        g.assign(n,{});
        calculated=false;
    }
    void add_edge(int from,int to,T cap){
        assert(0<=from&&from<n&&0<=to&&to<n);
        g[from].emplace_back(e.size());
        e.emplace_back(to,cap);
        g[to].emplace_back(e.size());
        e.emplace_back(from,directed?0:cap);
        U=max(U,cap);
    }
    bool bfs(T scale){
        lv.assign(n,-1);
        vector<int> q{s};
        lv[s]=0;
        for(int i=0;i<(int)q.size();i++){
            int u=q[i];
            for(int j:g[u]){
                int v=e[j].to;
                if(lv[v]==-1&&e[j].remain()>=scale){
                    q.emplace_back(v);
                    lv[v]=lv[u]+1;
                }
            }
        }
        return lv[t]!=-1;
    }
    T dfs(int u,int t,T f){
        if(u==t||f==0)return f;
        for(int &i=ptr[u];i<(int)g[u].size();i++){
            int j=g[u][i];
            int v=e[j].to;
            if(lv[v]==lv[u]+1){
                T res=dfs(v,t,min(f,e[j].remain()));
                if(res>0){
                    e[j].flow+=res;
                    e[j^1].flow-=res;
                    return res;
                }
            }
        }
        return 0;
    }
    T flow(){
        if(calculated)return max_flow;
        calculated=true;
        max_flow=0;
        for(T scale=scaling?1LL<<(63-__builtin_clzll(U)):1LL;scale>0;scale>>=1){
            while(bfs(scale)){
                ptr.assign(n,0);
                while(true){
                    T f=dfs(s,t,INF);
                    if(f==0)break;
                    max_flow+=f;
                }
            }
        }
        return max_flow;
    }
    pair<T,vector<int>> cut(){
        flow();
        vector<int> res(n);
        for(int i=0;i<n;i++)res[i]=(lv[i]==-1);
        return {max_flow,res};
    }
};

ll s[2][MxN], v[2][MxN], w[2][MxN];

signed main(int argc, char *argv[]) {
  int n, p0;
  cin >> n >> p0;
  for(int i=0; i<2; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> s[i][j];
    }
  }
  for(int i=0; i<2; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> v[i][j];
    }
  }
  Dinic<ll> dinic(n + 3, n + 1, n + 2);
  ll answer = 0ll;
  for(int i=1; i<=n; ++i) {
    w[0][i] = 2 * p0 * v[0][i];
    w[1][i] = 2 * p0 * v[1][i];
    for(int j=1; j<=n; ++j) {
      if(i == j) {
        continue;
      }
      ll x = max(s[0][i] * v[0][j], s[0][j] * v[0][i]);
      ll y = max(s[1][i] * v[1][j], s[1][j] * v[1][i]);
      dinic.add_edge(i, j, x + y);
      w[0][i] += x;
      w[1][i] += y;
    }
    dinic.add_edge(n + 1, i, w[0][i]);
    dinic.add_edge(i, n + 2, w[1][i]);
    answer += w[0][i] + w[1][i];
  }
  cout << (answer - dinic.flow()) / 2 << "\n";
  return 0;
}