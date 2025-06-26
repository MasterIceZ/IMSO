#include <iostream>
#include <set>
#include <string>
#include <vector>

const int HASH_POWER = 11239;

int k;
std::set<long long> st;

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t >> k;
  int n = (int) s.size();
  for(int i=0; i<n; ++i) {
    long long hsh = 1ll;
    int c = 0;
    for(int j=i; j<n; ++j) {
      c += (t[s[j] - 'a'] == '0');
      if(c > k) {
        break;
      }
      hsh = (hsh * HASH_POWER) + (s[j] - 'a');
      st.emplace(hsh);
    }
  }
  std::cout << st.size() << "\n";
  return 0;
}