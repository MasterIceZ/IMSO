#include <bits/stdc++.h>
#include "lightcolors.h"
 
using namespace std;
 
const int MxN = 100010;
 
int n, color[MxN], deg[MxN];
vector<int> adj[MxN];
priority_queue<pair<int, int>> q;
bitset<MxN> visited, blocked[4];
 
bool dfs_bipartite(int u, int p, int c) {
    if(color[u] != 0) {
        return (color[u] == c);
    }
    color[u] = c;
    for(auto x: adj[u]) {
        if(x == p) {
            continue;
        }
        if(dfs_bipartite(x, u, 3 - c) == false) {
            return false;
        }
    }
    return true;
}
 
vector<int> make_answer(int *color) {
    vector<int> res;
    for(int i=1; i<=n; ++i) {
        res.emplace_back(color[i]);
    }
    return res;
}
 
std::vector<int> lightcolors(int N, int M, std::vector<int> A, std::vector<int> B) {
    n = N;
    for(int i=0; i<=M-1; ++i) {
        int u = A[i] + 1, v = B[i] + 1;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
     
//    if(dfs_bipartite(1, 0, 1)) {
//        return make_answer(color);
//    }
 
    for(int i=1; i<=N; ++i) {
        q.emplace(0, i);
    }
//    memset(color, 0, sizeof color);
    while(!q.empty()) {
        auto [_deg, now] = q.top(); q.pop();
        if(visited[now]) {
            continue;
        }
        visited[now] = true;
        for(int i=1; i<=3; ++i) {
            if(!blocked[i][now]) {
                color[now] = i;
                break;
            }
        }
        assert(color[now] != 0);
        for(auto x: adj[now]) {
            if(!visited[x] && !blocked[color[now]][x]) {
                blocked[color[now]][x] = true;
                q.emplace(++deg[x], x);
            }
        }
    }
 
    return make_answer(color);
}
