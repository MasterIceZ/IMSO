#include "districts.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

struct point_t : std::pair<long long, long long> {
  using std::pair<long long, long long>::pair;
};

struct edge_t : std::pair<int, int> {
  using std::pair<int, int>::pair;
};

struct half_edge_t {
  int from, to, twin, next, face;

  half_edge_t(int _from, int _to, int _twin, int _next, int _face): 
    from(_from), to(_to), twin(_twin), next(_next), face(_face) {}
};

point_t operator-(const point_t &a, const point_t &b) {
  return point_t(a.first - b.first, a.second - b.second);
}

inline bool half_plane(point_t v) {
  return v.second > 0 || (v.second == 0 && v.first > 0);
}

inline long long cross(point_t a, point_t b) {
  return a.first * b.second - a.second * b.first;
}

int K, face_count, regions;
std::vector<long long> area;
std::vector<std::vector<int>> adj;

long long dfs(int u, int p, long long x) {
  long long sum = area[u];
  for(int v: adj[u]) {
    if(v == p) {
      continue;
    }
    sum += dfs(v, u, x);
  }
  if(sum >= x) {
    regions++;
    return 0;
  }
  return sum;
}

inline bool check(long long x) {
  regions = 0;

  dfs(0, -1, x);
  return regions >= K;
}

long long divide_districts(
    int N, int M, int K, 
    std::vector<int> X, 
    std::vector<int> Y, 
    std::vector<int> U, 
    std::vector<int> V
) {
  ::K = K;
  std::vector<point_t> points;
  for(int i=0; i<N; ++i) {
    points.emplace_back((long long) X[i], (long long) Y[i]);
  }
  std::vector<std::vector<edge_t>> pts_adj(N);
  std::vector<half_edge_t> half_edges;
  for(int i=0; i<M; ++i) {
    int u = U[i], v = V[i];
    pts_adj[u].emplace_back(v, i);
    pts_adj[v].emplace_back(u, i);

    int idx = 2 * i;
    half_edges.emplace_back(u, v, idx + 1, -1, -1);
    half_edges.emplace_back(v, u, idx, -1, -1);
  }

  for(int i=0; i<N; ++i) {
    std::sort(pts_adj[i].begin(), pts_adj[i].end(), [&](const edge_t &a, const edge_t &b) {
      point_t va = points[a.first] - points[i];
      point_t vb = points[b.first] - points[i];
      
      bool a_half = half_plane(va), b_half = half_plane(vb);
      if(a_half != b_half) {
        return a_half < b_half;
      }

      return cross(va, vb) < 0;
    });
  }

  for(int u=0; u<N; ++u) {
    for(int p=0; p<(int) pts_adj[u].size(); ++p) {
      int edge_idx = pts_adj[u][p].second;
      int outgoing = (half_edges[2 * edge_idx].from == u) ? 2 * edge_idx : 2 * edge_idx + 1;

      int prev_idx = (p - 1 + (int) pts_adj[u].size()) % pts_adj[u].size();
      int prev_idx_edge = pts_adj[u][prev_idx].second;
      int prev_outgoing = (half_edges[2 * prev_idx_edge].from == u) ? 2 * prev_idx_edge : 2 * prev_idx_edge + 1;

      half_edges[half_edges[prev_outgoing].twin].next = outgoing;
    }
  }
  for(int i=0; i<(int) half_edges.size(); ++i) {
    if(half_edges[i].next != -1) {
      continue;
    }
    half_edges[i].next = half_edges[i].twin;
  }

  face_count = 0;
  std::vector<bool> visited(half_edges.size(), false);
  std::vector<long long> raw_areas;
  for(int i=0; i<(int) half_edges.size(); ++i) {
    if(visited[i]) {
      continue;
    }
    int cur = i;
    long long raw_area = 0ll;
    while(!visited[cur]) {
      visited[cur] = true;
      half_edges[cur].face = face_count;
      raw_area += cross(points[half_edges[cur].from], points[half_edges[cur].to]);
      cur = half_edges[cur].next;
    }
    face_count++;
    raw_areas.emplace_back(raw_area);
  }

  std::vector<int> raw_to_face(face_count, -1);
  for(int i=0; i<face_count; ++i) {
    if(raw_areas[i] > 0ll) {
      raw_to_face[i] = (int) area.size();
      area.emplace_back(raw_areas[i]);
    }
  }

  adj.resize(face_count);
  for(int i=0; i<M; ++i) {
    int a_face = raw_to_face[half_edges[2 * i].face];
    int b_face = raw_to_face[half_edges[2 * i + 1].face];
    if(a_face != -1 && b_face != -1 && a_face != b_face) {
      adj[a_face].emplace_back(b_face);
      adj[b_face].emplace_back(a_face);
    }
  }

  long long l = 1ll, r = std::accumulate(area.begin(), area.end(), 0ll);
  while(l < r) {
    long long mid = (l + r + 1ll) >> 1ll;
    if(check(mid)) {
      l = mid;
    }
    else {
      r = mid - 1ll;
    }
  }
  
  return l;
}
