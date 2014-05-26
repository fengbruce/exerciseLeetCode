#include <vector>
#include <unordered_set>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		map<int, int> wordLen;
		unordered_set<string>::iterator dictIt = dict.begin();
		while(dictIt != dict.end()){
			wordLen[dictIt->size()] = 1;
			++dictIt;
		}
		vector<string> ret;
		int wordNum = wordLen.size();
		for(int i=0; i<wordNum; ++i){
			int offset = wordLen[i];
			if(offset > s.size()) continue;
			string subs = s.substr(0, 0+offset);
			if(dict.count(subs) == 0) continue;
			vector<string> subve = wordBreak(s.substr(offset), dict);
			for(int j=0; j<subve.size(); ++j){
				ret.push_back(subs+" "+subve[j]);
			}
		}
		return ret;
	}
};
