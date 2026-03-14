#include <algorithm>
#include <queue>
#include <vector>

std::vector<long long> capsize(std::vector<int> A, std::vector<int> B) {
	std::vector<int> compress;
	for(auto e: A) {
		compress.emplace_back(e);
	}
	for(auto e: B) {
		compress.emplace_back(e);
	}
	std::sort(compress.begin(), compress.end());
	compress.resize(std::unique(compress.begin(), compress.end()) - compress.begin());
	for(auto &x: A) {
		x = std::lower_bound(compress.begin(), compress.end(), x) - compress.begin();
	}
	for(auto &x: B) {
		x = std::lower_bound(compress.begin(), compress.end(), x) - compress.begin();
	}

	std::vector<int> freq(compress.size(), 0);
	long long sum = 0ll;
	for(auto x: A) {
		freq[x]++;
		sum += 1ll * compress[x];
	}
	
	std::priority_queue<std::pair<long long, int>> pq;
	for(int i=0; i<(int) compress.size(); ++i) {
		if(freq[i] == 0) {
			continue;
		}
		pq.emplace(1ll * compress[i] * freq[i], i);
	}

	std::vector<bool> done(compress.size(), false);
	std::vector<long long> answer;
	for(auto x: B) {
		if(!done[x]) {
			freq[x]++;
			sum += 1ll * compress[x];
			pq.emplace(1ll * compress[x] * freq[x], x);
		}
		while(!pq.empty()) {
			std::pair<long long, int> c = pq.top();
			pq.pop();
			if(done[c.second]) {
				continue;
			}
			sum -= c.first;
			done[c.second] = true;
			break;
		}
		answer.emplace_back(sum);
	}
	return answer;
}
