#include <stack>
#include <vector>

struct cartesian_tree {
  struct node_t {
    int v;
    node_t *l, *r;

    node_t(int _v):
      v(_v), l(nullptr), r(nullptr) {}
  };

  node_t *root;

  cartesian_tree():
    root(nullptr) {}
  
  void build_cartesian_tree(const std::vector<int> &a) {
    std::stack<node_t *> st;
    for(int i=0; i<(int) a.size(); ++i) {
      node_t *new_node = new node_t(a[i]);
      while(!st.empty() && st.top()->v < a[i]) {
        new_node->l = st.top();
        st.pop();
      }
      if(st.empty()) {
        root = new_node;
      }
      else {
        node_t *top = st.top();
        st.pop();
        top->r = new_node;
        st.push(top);
      }
      st.push(new_node);
    }
  }
};