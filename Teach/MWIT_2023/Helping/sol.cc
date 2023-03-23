// sol by lnw ttamx orz orz orz
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m,k,s;
        cin >> n >> m >> k >> s;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].emplace_back(v);
        }
        vector<vector<int>> dist(n+1,vector<int>(n+1,n+1));
        for(int i=1;i<=n;i++){
            queue<pair<int,int>> q;
            q.emplace(i,0);
            while(!q.empty()){
                auto [u,d]=q.front();
                q.pop();
                for(auto v:adj[u]){
                    if(d+1>=dist[i][v])continue;
                    dist[i][v]=d+1;
                    q.emplace(v,d+1);
                }
            }
        }
        int ans1=2e9,ans2=-1;
        for(int i=1;i<=n;i++){
            if(dist[i][i]>n)continue;
            int d=dist[s][i];
            if(i==s)d=0;
            int res=d+(k-1)*dist[i][i];
            if(res<ans1){
                ans1=res;
                ans2=i;
            }
        }
        if(ans2==-1)cout << -1 << '\n';
        else cout << ans1 << ' ' << ans2 << '\n';
    }
}
