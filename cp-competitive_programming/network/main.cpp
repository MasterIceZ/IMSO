#include <iostream>
#include "network_marketing.h"

using namespace std;

int main(){
    CP::network_marketing<int> tree;
    char op;
    while(1){
        cin>>op;
        if(op == 's'){
            int c,p;
            cin>>c>>p;
            tree.setparent(c,p);
        }
        else if (op == 'c')
        {
            int x;
            cin>>x;
            cout<<tree.count_children(x)<<'\n';
        }
        else if (op == 'q')
        {
            break;
        }
        else{
            continue;
        }
        
    }
}