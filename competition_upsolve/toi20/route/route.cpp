#include <vector>
#include <utility>

using namespace std; 

std::vector<std::pair<int, int>> route(int N, std::vector<int> W) {
	vector<pair<int, int>> edges;
	int cur = 1, out = 1;
	for(int i=1; i<=(int) W.size(); ++i) {
		if((int) W.size() - i + 1 + cur > N) {
			if(out >= cur) {
				out = 1;
				cur++;
			}
			edges.emplace_back(out++, cur);
			continue;
		}
		for(int j=i; i<=(int) W.size(); ++i) {
			edges.emplace_back(cur, cur + j - i + 1);
		}
		break;
	}
	return edges;
}
