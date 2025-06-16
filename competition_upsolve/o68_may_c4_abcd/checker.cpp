#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream inf(argv[1]);
  ifstream ans(argv[2]);
  ifstream ouf(argv[3]);

  int is_correct, count;

  string output1;
  ouf >> output1;

  if (output1 != "THISISAKEY") {
    cout << "0.0" << endl;
    cerr << "translate:wrong" << endl;
  } else {
    ouf >> is_correct >> count;
    if ((!is_correct) || (count > 4005)) {
      cout << "0.0" << endl;
      cerr << "translate:wrong" << endl;
    } else {
      if (count <= 1177) {
        cout << "1.0" << endl;
        cerr << "translate:success" << endl;
      } else if (count <= 1507) {
        double point;
        double fract = (double)(count - 1177) / (double)(1507 - 1177);
        point = 1.0 - 0.9 * fract;
        cout << setprecision(6) << point << endl;
        cerr << "Partial correct. Making " << count << " calls." << endl;
      } else {
        double point;
        double fract = (double)(count - 1507) / (4005 - 1507);
        point = 0.10 * (1.0 - fract);
        cout << setprecision(6) << point << endl;
        cerr << "Partial correct. Making " << count << " calls." << endl;
      }
    }
  }
  return 0;
}