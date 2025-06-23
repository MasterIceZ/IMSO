#include <stack>

int n, *a;
int root, *l, *r;

void build_cartesian_tree() {
  std::stack<int> st;
  root = -1;
  for(int i=1; i<=n; ++i) {
    l[i] = r[i] = 0;
  }
  for(int i=1; i<=n; ++i) {
    while(!st.empty() && a[st.top()] < a[i]) {
      l[i] = st.top();
      st.pop();
    }
    if(st.empty()) {
      root = i;
    }
    else {
      r[st.top()] = i;
    }
    st.emplace(i);
  }
};