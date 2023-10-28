#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

// indexing start from 0
lli N, M, K, P;
lli G[20001];
vector<vector<pair<lli, lli>>> adj_list(20001);
lli parent[20001];
lli value[20001];
lli depth[20001];
bool founddepth[20001] = {false};

queue<lli> tocmp;

bool printorder(lli a, lli b) {
    return depth[a] > depth[b];
}

void cmp() {
    lli u = tocmp.front();
    tocmp.pop();
    for (pair<lli, lli> vw : adj_list[u]) {
        lli newval = value[u] + vw.second;
        if (newval <= value[vw.first]) {
            value[vw.first] = newval;
            parent[vw.first] = u;
            tocmp.push(vw.first);
        }
    }
}

void depthfind(lli u) {
    if (founddepth[u]) return;
    founddepth[u] = true;
    if (parent[u] == -1) {
        depth[u] = -1;
        return;
    }
    if (u == P) {
        depth[u] = 0;
        return;
    }
    depthfind(parent[u]);
    if (depth[parent[u]] != -1) depth[u] = depth[parent[u]] + 1;
    else depth[u] = -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> P;
    for (lli i = 0; i < N; i++) {
        value[i] = 1e18;
        parent[i] = -1;
    }
    value[P] = 0;
    parent[P] = P;
    for (lli i = 0; i < K; i++) cin >> G[i];
    for (lli i = 0; i < M; i++) {
        lli u, v, w;
        cin >> u >> v >> w;
        adj_list[u].emplace_back(v, w);
        adj_list[v].emplace_back(u, w);
    }
    
    tocmp.push(P);
    while(!tocmp.empty()) cmp();
    
    for (lli i = 0; i < N; i++) depthfind(i);
    for (lli i = 0; i < K; i++) cout << value[G[i]] << " ";
    cout << "\n";

    // debugging
    // for (lli i = 0; i < N; i++) cout << i << " " << parent[i] << " " << depth[i] << "\n";

    lli po[N];
    for (lli i = 0; i < N; i++) po[i] = i;
    sort(po, po+N, printorder);
    vector<pair<lli,lli>> output;
    output.reserve(N);
    lli ct = 0;
    for (lli i : po) {
        if (depth[i] < 1) break;
        ct++;
        output.emplace_back(min(i, parent[i]), max(i, parent[i]));
    }
    cout << ct << "\n";
    for (pair<lli, lli> i : output) cout << i.first << " " << i.second << "\n";
    return 0;
}
