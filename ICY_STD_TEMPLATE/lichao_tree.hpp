#include <algorithm>

const long long INF = 1e18;

struct line_t {
  long long m, c;

  line_t(long long _m, long long _c):
    m(_m), c(_c) {}
  
  inline long long eval(long long x) {
    return m * x + c;
  }
};

struct lichao_tree {
  struct node_t {
    line_t line;
    node_t *l, *r;

    node_t(line_t _line):
      line(_line), l(nullptr), r(nullptr) {}
  };

  node_t *root;
  long long l_bound, r_bound;

  lichao_tree(long long _l_bound, long long _r_bound):
    root(nullptr), l_bound(_l_bound), r_bound(_r_bound) {}
  
  void insert(line_t line) {
    insert_line(root, line, l_bound, r_bound);
  }
  long long query(long long x) {
    return query_line(root, x, l_bound, r_bound);
  }
  void insert_line(node_t *&node, line_t line, long long l, long long r) {
    if(node == nullptr) {
      node = new node_t(line);
      return;
    }
    long long mid = (l + r) / 2ll;
    bool left_better = line.eval(l) < node->line.eval(l);
    bool mid_better = line.eval(mid) < node->line.eval(mid);

    if(mid_better) {
      std::swap(node->line, line);
    }
    if(l == r) {
      return ;
    }
    if(left_better != mid_better) {
      insert_line(node->l, line, l, mid);
    }
    else {
      insert_line(node->r, line, mid + 1, r);
    }
  }
  long long query_line(node_t *node, long double x, long double l, long double r) {
    if(node == nullptr) {
      return INF;
    }
    long long res = node->line.eval(x);
    long long mid = (l + r) / 2ll;
    if (x < mid && node->l != nullptr) {
      res = std::min(res, query_line(node->l, x, l, mid));
    } else if (x >= mid && node->r != nullptr) {
      res = std::min(res, query_line(node->r, x, mid, r));
    }
    return res;
  }
};