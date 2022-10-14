#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t, answer = 0;
	scanf("%d %d", &n, &t);
	priority_queue<int> pq;
	for(int i=1, x; i<=n; ++i){
		while(!pq.empty() && pq.top() >= t - i){
			pq.pop();
		}
		scanf("%d", &x);
		if(max(x, i) < t){
			pq.emplace(x - i);
		}
		answer = max(answer, (int) pq.size());
	}
	printf("%d", answer);
	return 0;
}
