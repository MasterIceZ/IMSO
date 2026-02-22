#include <vector>
#include <map>
#include <iostream>
#include "student.h"

using std::cout;
using std::endl;
using std::cin;

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries);

int main() {
  std::ios_base::sync_with_stdio(false); cin.tie(nullptr);

  std::map<long long,int>  data;
  std::vector<std::pair<int,int>> queries;
  std::vector<size_t> r;
  int N,M;
  cin >> N >> M;

  // read data
  for (int i = 0;i < N;i++) {
    int p,q;
    cin >> p >> q;
    data[p] = q;
  }

  // read query
  for (int i = 0;i < M;i++) {
    int a,b;
    cin >> a >> b;
    queries.push_back({a,b});
  }

  // call the function
  r = count_value(data,queries);

  // display output
  for (auto &x : r) {
    cout << x << " ";
  }
  cout << endl;
}
