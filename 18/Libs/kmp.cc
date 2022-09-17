template<class T>
class KMP{
protected:
	const unsigned int offset = (1 << 4);
private:
	std::vector<int> res;
	std::string pattern;
	unsigned int *pt;
	size_t sz;
public:
	KMP(std::string _pattern): sz(_pattern.size()){
		pattern = " " + _pattern;
		pt = (unsigned int *) calloc(sz + offset, sizeof(unsigned int));
		for(int i=2, j=0; i<=(int) sz; ++i){
			while(j > 0 && pattern[i] != pattern[j + 1]){
				j = pt[j];
			}
			j += (pattern[i] == pattern[j + 1]);
			pt[i] = j;
		}
	}
	std::vector<int> search_idx(string text){
		int n = text.size();
		text = " " + text;
		res.clear();
		for(int i=1, j=0; i<=n; ++i){
			while(j > 0 && pattern[j + 1] != text[i]){
				j = pt[j];
			}
			j += (text[i] == pattern[j + 1]);
			if(j == (int) sz){
				res.emplace_back(i - j + 1);
			}
		}	
		return res;
	}
	bool search(string text){
		int n = text.size();
		text = " " + text;
		for(int i=1, j=0; i<=n; ++i){
			while(j > 0 && pattern[j + 1] != text[i]){
				j = pt[j];
			}
			j += (text[i] == pattern[j + 1]);
			if(j == (int) sz){
				return true;
			}
		}
		return false;
	}
};

// KMP<int> kmp({5, 6, 5, 5, 6});
