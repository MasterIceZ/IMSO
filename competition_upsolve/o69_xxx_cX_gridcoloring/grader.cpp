#include "gridcoloring.h"
#include <iostream>

int main(){
    int X, Y, Q;
    std::cin >> X >> Y >> Q;
    std::vector<std::vector<char>> G;
    for(int i = 0; i < X; i++){
        char line[2048];
        std::cin >> line;
        std::vector<char> cur;
        for(char* ptr = line; *ptr; ptr++) cur.push_back(*ptr);
        G.push_back(cur);
    }
    init_grid(X, Y, Q, G);
    while(Q--){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << answer_query(x1, y1, x2, y2) << std::endl;
    }
    return 0;
}
