#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		size_t i=0,j;
		while (i < s.size()) {
			j = s.find(' ', i);
			if (j == string::npos) j = s.size();
			
			reverse(s.begin()+i,s.begin()+j);
			i = j+1;
		}
		return s;
	}
};

int main() {
	Solution sol;	
	string in = "Let's take LeetCode contest";
	//reverse(in.begin()+1, in.end());
	//cout << in;
	cout << sol.reverseWords(in);
}