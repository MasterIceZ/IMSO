#include <iostream>
#include "priority_queue.h"
#include "student-s4.h"

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
    CP::priority_queue<int> pq;
    int n,p,q;
    cin>>n;
    for(int i = 0; i<n ; i++){
        pq.push(i);
    }
    cin>>p>>q;
    cout<<pq.lca(p,q);
    return 0;
}