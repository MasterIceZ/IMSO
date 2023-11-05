#include <bits/stdc++.h>

using namespace std;

struct trie_node_t {
  trie_node_t *nxt[2];
  trie_node_t() {
    nxt[0] = nxt[1] = NULL;
  }
};

inline void update(trie_node_t *cur, int val) {
  for(int state=20; state>=0; --state) {
    int b = (val >> state) & 1;
    if(cur->nxt[b] == NULL) {
      cur->nxt[b] = new trie_node_t();
    }
    cur = cur->nxt[b];
  }
}

inline int query(trie_node_t *cur, int val) {
  int res = 0;
  for(int state=20; state>=0; --state) {
    int b = (val >> state) & 1, going;
    res = (res << 1);
    if(cur->nxt[b] == NULL) {
      going = !b;
    }
    else {
      going = b;
      res |= 1;
    }
    cur = cur->nxt[going];
  }
  return res;
}

const int MxN = 200020;
int a[MxN], pref_xor[MxN], answer[MxN];

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  trie_node_t *root = new trie_node_t();

  int n;
  cin >> n;
  for(int i=1; i<=n-1; ++i) {
    cin >> a[i];
    pref_xor[i] = pref_xor[i - 1] ^ a[i];
    update(root, pref_xor[i]);
  }
  answer[1] = n - 1;
  for(int i=0; i<=n-1; ++i) {
    int qry = query(root, ~i);
    if(qry == n - 1) {
      answer[1] = i;
      break;
    }
  }
  for(int i=1; i<=n; ++i) {
    if(i != 1) {
      answer[i] = answer[i - 1] ^ a[i - 1];
    }
    cout << answer[i] << " ";
  }
  cout << "\n";
  return 0;
}