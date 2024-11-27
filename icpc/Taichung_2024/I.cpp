#include <bits/stdc++.h>

using namespace std;

struct node_t;
using pnode_t = node_t *;
struct node_t {
  map<int, pnode_t> nxt;
  set<pair<int, int>> mem;
};

struct trie_t {
  node_t root, current_node;
  void insert(string s) {
    pnode_t cur = &root;
    for(auto x: s) {
      if(cur->nxt.find(x) == cur->nxt.end()) {
        cur->nxt[x] = new node_t();
      }
      cur = cur->nxt[x];
      cur->mem.emplace();
    }
  }
  void erase(string s) {
    pnode_t cur = &root;
    cur->mem.erase(make_pair(1, 1));
    for(auto x: s) {
      cur = cur->nxt[x];
      cur->mem.erase(make_pair(1, 1));
    }
  }
  void append(string s) {
    for(auto x: s) {
      current_node = 
    }
  }
} t;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    string opr;
    cin >> opr;
    if(opr == "add") {
      int id;
      string p;
      cin >> id >> p;

    }
  }
  return 0;
}