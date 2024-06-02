#include "sofautils.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream inf(argv[1]);
    ifstream ans(argv[2]);
    ifstream ouf(argv[3]);
    double s;
    ans >> s;
    ObstacleSet obs;
    obs.read_input(inf);
    int topv =
        find(obs.vertices.begin(), obs.vertices.end(), make_pair(0.0, 100.0)) -
        obs.vertices.begin();
    if (topv == obs.vertices.size()) {
        obs.vertices.push_back({0.0, 100.0});
    }
    int btmv =
        find(obs.vertices.begin(), obs.vertices.end(), make_pair(0.0, -100.0)) -
        obs.vertices.begin();
    if (btmv == obs.vertices.size()) {
        obs.vertices.push_back({0.0, -100.0});
    }
    int topvv = obs.vertices.size();
    obs.vertices.push_back({0.0, 10000.0});
    int btmvv = obs.vertices.size();
    obs.vertices.push_back({0.0, -10000.0});
    obs.edges.push_back({topv, topvv});
    obs.edges.push_back({btmv, btmvv});
    Sofa sofa;
    sofa.read_input(ouf);
    for (auto p : sofa.poly) {
        if (p.first > -100 || p.first < -200 || p.second < -500 ||
            p.second > 500) {
            cout << 0.0 << endl;
            cerr << "Output sofa starting point is out of bound" << endl;
            return 0;
        }
    }
    int moves;
    ouf >> moves;
    cout << fixed << setprecision(6);
    for (int i = 0; i < moves; i++) {
        string cmdtype;
        ouf >> cmdtype;
        if (cmdtype[0] == 'F') {
            double x, y;
            ouf >> x >> y;
            if (abs(x) > 500 || abs(y) > 500) {
                cout << 0.0 << endl;
                cerr << "Translation too large" << endl;
                return 0;
            }
            if (!sofa.translate_sofa(obs, {x, y})) {
                cout << 0.0 << endl;
                cerr << "Invalid translation" << endl;
                return 0;
            }
        } else if (cmdtype[0] == 'R') {
            double d, x, y;
            ouf >> d >> x >> y;
            if (d < -360.0 || d > 360.0 || abs(x) > 500 || abs(y) > 500) {
                cout << 0.0 << endl;
                cerr << "Invalid rotation config" << endl;
                return 0;
            }
            if (!sofa.rotate_sofa(obs, {x, y}, d * acos(-1) / 180.0)) {
                cout << 0.0 << endl;
                cerr << "Invalid rotation" << endl;
                return 0;
            }
        } else {
            cout << 0.0 << endl;
            cerr << "Invalid Command" << endl;
            return 0;
        }
    }
    for (auto p : sofa.poly) {
        if (p.first < 100) {
            cout << 0.0 << endl;
            cerr << "Output sofa isn\'t moved to the right" << endl;
            return 0;
        }
    }
    double t = sofa.area();
    if (t >= s) {
        cout << 1.0 << endl;
        cerr << "translate:success" << endl;
    } else {
        cout << 0.4 + 0.6 * t / s << endl;
        cerr << "translate:partial" << endl;
    }
    // cout << 1.0 << endl;
    // cerr << "Correct Answer with area " << sofa.area() << endl;
    return 0;
}