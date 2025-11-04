#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

inline bool is_single(const std::vector<std::pair<long long, long long>> &queries) {
  std::vector<std::pair<long long, long long>> sorted = queries;
  std::sort(sorted.begin(), sorted.end());

  for(int i=1; i<(int) sorted.size(); ++i) {
    if(sorted[i - 1].second >= sorted[i].first) {
      return false;
    }
  }
  return true;
}

signed main(int argc, char *argv[]) {
	long long n;
	int q;
	std::cin >> n >> q;
  std::vector<std::pair<long long, long long>> queries(q);
  for(auto &[l, r] : queries) {
    std::cin >> l >> r;
  }
	if(q == 1) {
    long long l = queries[0].first, r = queries[0].second;
		std::cout << n - (r - l + 1ll) << "\n";
    return 0;
  }
  else if(is_single(queries)) {
    long long total_covered = 0ll;
    for(auto &[l, r] : queries) {
      total_covered += (r - l + 1ll);
      std::cout << n - total_covered << "\n";
    }
  }
	else if(n <= 1000 && q <= 1000) {
		std::bitset<1000> b;
		for(auto &[l, r] : queries) {
      l--, r--;
			for(int i=l; i<=r; ++i) {
				b[i] = true;
			}
			std::cout << std::min(n, 1000ll) - (long long) b.count() << "\n";
		}
	}
  else if(q == 2) {
    auto [l1, r1] = queries[0];
    std::cout << n - (r1 - l1 + 1ll) << "\n";
    auto [l2, r2] = queries[1];
    long long total_covered = (r1 - l1 + 1ll) + (r2 - l2 + 1ll);
    if(l2 <= r1 && l1 <= r2) {
      long long overlap = std::min(r1, r2) - std::max(l1, l2) + 1ll;
      total_covered -= overlap;
    }
    std::cout << n - total_covered << "\n";
  }
  else if(n <= 1000000) {
    std::set<int> st;
    for(int i=1; i<=n; ++i) {
      st.emplace(i);
    }
    for(auto &[l, r] : queries) {
      auto it = st.lower_bound(l);
      while(it != st.end() && *it <= r) {
        it = st.erase(it);
      }
      std::cout << (long long) st.size() << "\n";
    }
  }
  else {
    std::set<std::pair<long long, long long>> st;
    for(auto &[l, r] : queries) {
      auto it = st.lower_bound(std::make_pair(l, 0));
      
      while(it != st.end() && it->first <= r) {
        l = std::min(l, it->first);
        r = std::max(r, it->second);
        it = st.erase(it);
      }
      if(it != st.begin()) {
        --it;
        if(it->second >= l) {
          l = std::min(l, it->first);
          r = std::max(r, it->second);
          it = st.erase(it);
        }
      }
      st.emplace(l, r);
      long long total_covered = 0ll;
      for(auto &[x, y] : st) {
        total_covered += (y - x + 1ll);
      }

      std::cout << n - total_covered << "\n";
    }
  }
}
