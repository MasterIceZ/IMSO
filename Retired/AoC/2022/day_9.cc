#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int> ;

set<pii> st, st2;

const int d8i[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int d8j[] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline void follow(pii &head, pii &tail){
	bool in_bound = (head == tail);
	for(int k=0; k<8; ++k){
		in_bound |= (head == make_pair(tail.first + d8i[k], tail.second + d8j[k]));
	}
	if(in_bound){
		return ;
	}
	pii diff = make_pair(abs(head.first - tail.first), abs(head.second - tail.second));
	if(diff.first != 0){
		int dd = head.first - tail.first;
		if(dd > 0){
			tail.first++;
		}
		else{
			tail.first--;
		}
	}
	if(diff.second != 0){
		int dd = head.second - tail.second;
		if(dd > 0){
			tail.second++;
		}
		else{
			tail.second--;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int N = 2000;
	
	vector<pii> v(10);
	for(int i=0; i<=9; ++i){
		v[i] = make_pair(1, 1);
	}
	st.emplace(1, 1);
	st2.emplace(1, 1);

	for(int i=1; i<=N; ++i){
		char o;
		int a;
		cin >> o >> a;
		if(o == 'U'){
			while(a--){
				v[0].first--;
				for(int j=1; j<=9; ++j){
					follow(v[j - 1], v[j]);
					st.emplace(v[1]);
					st2.emplace(v[9]);
				}
			}
		}
		else if(o == 'D'){
			while(a--){
				v[0].first++;
				for(int j=1; j<=9; ++j){
					follow(v[j - 1], v[j]);
					st.emplace(v[1]);
					st2.emplace(v[9]);
				}
			}
		}
		else if(o == 'R'){
			while(a--){
				v[0].second++;
				for(int j=1; j<=9; ++j){
					follow(v[j - 1], v[j]);
					st.emplace(v[1]);
					st2.emplace(v[9]);
				}
			}
		}
		else{
			while(a--){
				v[0].second--;
				for(int j=1; j<=9; ++j){
					follow(v[j - 1], v[j]);
					st.emplace(v[1]);
					st2.emplace(v[9]);
				}
			}
		}
	}

	cout << "Answer #1: " << (int) st.size() << "\n";
	cout << "Answer #2: " << (int) st2.size() << "\n";
	
	return 0;
}
