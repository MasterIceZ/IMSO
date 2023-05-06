#include <iostream>
#include <assert.h>
#include "flight.cpp"

int main(){
    int N, Q;
    assert(std::cin >> N >> Q);
    initialize(N, Q);
    for(int i=1;i<=Q;i++){
        int t;
        assert(std::cin >> t);
        if(t==1){
            int u,v;
            assert(std::cin >> u >> v);
            add(u,v);
        }else{
            int k;
            assert(std::cin >> k);
            std::cout << ask(k) << " ";
        }
    }
}
