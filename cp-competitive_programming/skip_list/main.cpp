#include <bits/stdc++.h>
#include "list.h"
#include "student.h"

using namespace std;

void process_case() {
    CP::list<string> lst;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "in") {
            int pos;
            string val;
            cin >> pos;
            cin >> val;
            auto it = lst.begin();
            for (int i = 0; i < pos; ++i) ++it;
            lst.insert(it, val);

        } else if (cmd == "er") {
            int pos;
            cin >> pos;
            auto it = lst.begin();
            for (int i = 0; i < pos; ++i) ++it;
            lst.erase(it);

        } else if (cmd == "at") {
            int pos;
            cin >> pos;
            cout << lst.at(pos) << endl;

        } else if (cmd == "si") {
            cout << lst.size() << endl;

        } else if (cmd == "pnn") {
            lst.print_with_nextnext();

        } else if (cmd == "p") {
            lst.print();
            
        } else if (cmd == "q") {
            break;
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q--) {
        process_case();
    }

    return 0;
}
