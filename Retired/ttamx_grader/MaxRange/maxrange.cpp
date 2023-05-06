#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxrange(int N, int K, std::vector<int> A){
	deque<int> minn, maxx;
	vector<int> answer;
	for(int i=0; i<N; ++i){
		while(!maxx.empty() && A[maxx.back()] <= A[i]){
			maxx.pop_back();
		}
		while(!maxx.empty() && i - maxx.front() >= K){
			maxx.pop_front();
		}
		maxx.emplace_back(i);
		while(!minn.empty() && A[minn.back()] >= A[i]){
			minn.pop_back();
		}
		while(!minn.empty() && i - minn.front() >= K){
			minn.pop_front();
		}
		minn.emplace_back(i);
		answer.emplace_back(A[maxx.front()] - A[minn.front()]);
	}
    return *max_element(answer.begin(), answer.end()) ;
}
