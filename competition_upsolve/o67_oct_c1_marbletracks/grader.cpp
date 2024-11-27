#include "marbletracks.h"
#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>

using std::vector;
using std::tuple;
using std::get;

int main() {
    int n, q;
    scanf("%d %d",&n,&q);
    vector<int> v(n);
    vector<tuple<int, int, int>>qy(q);
    for(int i = 0;i < n;i++) {
        scanf("%d",&v[i]);
    }
    for(int i = 0;i < q;i++) {
        scanf("%d %d %d", &get<0>(qy[i]), &get<1>(qy[i]), &get<2>(qy[i]));
    }
    vector<int> vs = observe(n,q,v,qy);
    for(auto i: vs) {
        printf("%d\n",i);
    }
}