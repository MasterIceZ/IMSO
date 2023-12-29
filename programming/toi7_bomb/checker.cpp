#include <bits/stdc++.h>

using namespace std;

const string FAILSTR = "FAIL-ioaijjidijojdisjdisjdsadasdasd";

void wrong_answer() {
  cout << "Incorrect\n";
  cout << "0\n";
  // cerr << "wrong answer!\n";
  exit(0);
}

void accepted() {
  cout << "Correct\n";
  cout << "100\n";
  // cerr << "accepted!\n";
  exit(0);
}

string readWord(ifstream& in) {
  string out;
  if(in >> out) {
    return out;
  }
  return FAILSTR;
}

long long readInt(ifstream& in, long long mn=LLONG_MIN, long long mx=LLONG_MAX, bool flag=false) {
  string s = readWord(in);
  char *p;
  long long tmp = strtoll(s.c_str(), &p, 10);
  if(*p != 0 || tmp < mn || tmp > mx) {
    wrong_answer();
  }
  return tmp;
}

int main(int argc, char * argv[]) {
  ifstream input_file(argv[1]);
  ifstream output_file(argv[2]);
  ifstream solution_output(argv[3]);

  vector<pair<int, int>> user, sol;
  
  sort(user.begin(), user.end());
  sort(sol.begin(), sol.end());
  
  if(user != sol) {
    wrong_answer();
  }
  else{
    accepted();
  }
  return 0;
}
