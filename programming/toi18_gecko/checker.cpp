#include <bits/stdc++.h>

using namespace std;

const string FAILSTR = "FAIL-ioaijjidijojdisjdisjdsadasdasd";

void wrong_answer() {
  cout << "Incorrect\n";
  cout << "0\n";
  // cerr << "wrong answer!\n";
  exit(0);
}

void accepted() {
  cout << "Correct\n";
  cout << "100\n";
  // cerr << "accepted!\n";
  exit(0);
}

string readWord(istream& in) {
  string out;
  if(in >> out) {
    return out;
  }
  return FAILSTR;
}

long long readInt(istream& in, long long mn=LLONG_MIN, long long mx=LLONG_MAX, bool flag=false) {
  string s = readWord(in);
  char *p;
  long long tmp = strtoll(s.c_str(), &p, 10);
  if(*p != 0 || tmp < mn || tmp > mx) {
    wrong_answer();
  }
  return tmp;
}

void dfs(int u, int p, vector<vector<pair<int, int>>> &adj, vector<bool> &visited) {
  visited[u] = true;
  for (auto x : adj[u])
  {
    if(x.first == p) {
      continue;
    }
    dfs(x.first, u, adj, visited);
  }
}

int main(int argc, char * argv[]) {
  ifstream input_file(argv[1]);
  ifstream output_file(argv[2]);
  ifstream solution_output(argv[3]);

  int n = readInt(input_file, 1, 20000);
  int m = readInt(input_file, 1, 200000);
  int k = readInt(input_file, 1, n - 1);
  int p = readInt(input_file, 0, n - 1);

  vector<int> gecko(k);
  for(auto &x: gecko) {
    x = readInt(input_file, 0, n - 1);
  }

  for (int i = 1; i <= k; ++i) {
    int user_s = readInt(solution_output, 0);
    int solution_s = readInt(output_file, 0);
    if(user_s != solution_s) {
      wrong_answer();
    }
  }
  
  int user_q = readInt(solution_output, 0, m);
  int solution_q = readInt(output_file, 0, m);

  if(user_q != solution_q) {
    wrong_answer();
  }

  map<pair<int, int>, int> weight;

  for(int i = 1; i <= m; ++i) {
    int u = readInt(input_file, 0, n - 1);
    int v = readInt(input_file, 0, n - 1);
    int w = readInt(input_file, 1, 100000);

    weight[make_pair(u, v)] = w;
  }

  vector<vector<pair<int, int>>> adj(n);

  for (int i = 1; i <= user_q; ++i) {
    int u = readInt(solution_output, 0, n - 1);
    int v = readInt(solution_output, 0, n - 1);

    pair<int, int> edge = make_pair(u, v);

    if(weight.find(edge) == weight.end()) {
      wrong_answer();
    }

    adj[u].emplace_back(v, weight[edge]);
    adj[v].emplace_back(u, weight[edge]);
  }

  // dfs from k
  vector<bool> visited(n, false);
  dfs(k, -1, adj, visited);

  for(auto x: gecko) {
    if(!visited[x]) {
      wrong_answer();
    }
  }

  accepted();

  return 0;
}