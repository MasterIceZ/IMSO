#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
  vector<int> parent, rank;

  DSU(int n) {
    parent.resize(n);
    rank.resize(n);
    for(int i = 0; i < n; i++){
      parent[i] = i;
      rank[i] = 1;
    }
  }

  int find(int i) {
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
  }
  
  void unite(int x, int y) {
    int s1 = find(x), s2 = find(y);
    if (s1 != s2) {
      if (rank[s1] < rank[s2]) parent[s1] = s2;
      else if(rank[s1] > rank[s2]) parent[s2] = s1;
      else parent[s2] = s1, rank[s1]++;
    }
  }
};

bool comparator(tuple<int,int,int> &a,tuple<int,int,int> &b){
  auto [a1,a2,a3]=a;  
  auto [b1,b2,b3]=b;  
  if(a3<=b3)return true;
  return false;
}

ll MST(int V, vector<tuple<int,int,int>> &edges){
  sort(edges.begin(), edges.end(), comparator);

  DSU dsu(V+5);
  ll cost = 0;
  int count = 0;

  for(auto& [u,v,w] : edges){
    if(dsu.find(u) != dsu.find(v)){
      dsu.unite(u, v);
      cost += (ll)w;
      count++;
    }
  }
  if(count != V - 1){return -1;}
  return cost;
}

signed main(signed argc, char *argv[]) {
  FILE *inf, *ans, *ouf;

  inf = fopen(argv[1], "r"); //input
  ouf = fopen(argv[2], "r"); //user output
  ans = fopen(argv[3], "r"); //solution
  
  int N, M;
  assert(fscanf(inf, "%d %d", &N, &M) == 2);

  vector<int> W(M);
  ll sW = 0;
  for(int i = 0; i < M; i++){
    assert(fscanf(inf, "%d", &W[i]) == 1);
    sW += (ll)W[i];
  }

  vector<tuple<int,int,int>> ans_edge, output_edge;
  vector<int> output_weights;

  set<pair<int,int>> edges;

  for(int i = 0; i < M; i++){
    int u,v,w;
    fscanf(ans, "%d %d %d", &u, &v, &w);
    ans_edge.push_back({u,v,w});
  }
  for(int i = 0; i < M; i++){
    int u,v,w;
    fscanf(ouf, "%d %d %d", &u, &v, &w);
    if(u<1 || u>N || v<1 || v>N){
      cout << "Incorrect\n";
      cout << "0\n";
      exit(0);
    }
    output_edge.push_back({u,v,w});
    edges.insert({min(u,v), max(u,v)});
    output_weights.push_back(w);
  }
  
  sort(output_weights.begin(), output_weights.end());
  sort(W.begin(), W.end());

  if(edges.size() != M || output_weights != W) {
    cout << "Incorrect\n";
    cout << "0\n";
    exit(0);
  }
  
  ll S = sW - MST(N, ans_edge);
  ll T = sW - MST(N, output_edge);

  if(T == -1){
    cout << "Incorrect\n";
    cout << "0\n";
    exit(0);
  }
  else if(S >= T) {
    cout << "Correct\n";
    cout << "100\n";
  }
  else{
    double score = pow((double)S / (double)T, 2);
    cout << "Partially Correct\n";
    cout << (int)(score*100) << "\n";
  }
  return 0;
}

