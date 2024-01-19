#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxA = 3000030;

struct event_t {
  int pos, height, width;
  bool operator < (const event_t &o) const {
    if(pos != o.pos) {
      return pos < o.pos;
    }
    if(height != o.height) {
      return height < o.height;
    }
    return width < o.width;
  }
  event_t(int _pos, int _height, int _width):
    pos(_pos), height(_height), width(_width) {}
};

struct fenwick_tree {
  int t[MxA];
  void update(int idx, int v) {
    for(; idx<MxA; idx+=idx&-idx) {
      t[idx] += v;
    }
  }
  int query(int idx) {
    int v = 0;
    for(; idx>0; idx-=idx&-idx) {
      v += t[idx];
    }
    return v;
  }
  int find(int v) {
    int l = 1, r = 1000000;
    while(l < r) {
      int mid = (l + r) >> 1;
      cerr << l << " " << r << "\n";
      if(query(mid) <= v) {
        r = mid;
      }
      else {
        l = mid + 1;
      }
    }
    return l;
  }
};

fenwick_tree fw;
vector<event_t> line;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  for(int i=1, s, h, w, o; i<=n; ++i) {
    cin >> s >> h >> w >> o;
    line.emplace_back(s, h, o);
    line.emplace_back(s + w, h, -o);
  }
  cerr << "DEBUG\n";
  int cnt = 0;
  sort(line.begin(), line.end());
  for(int i=0; i<line.size()-1; ++i) {
    fw.update(0, line[i].width);
    fw.update(line[i].height, -line[i].width);
    cerr << fw.find(t + 1) << " " << fw.find(t) << "\n";
    cnt += (line[i + 1].pos - line[i].pos) * (fw.find(t + 1) - fw.find(t));
  }
  cout << cnt;
  return 0;
}