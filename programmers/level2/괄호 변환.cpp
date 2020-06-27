#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
string p = "()";
int getBalance(string& s) {
	int ret = 0;
	int l=0, r=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') l++;
		else r++;
		if (l == r) {
			ret = i+1;
			break;
		}
	}
	return ret;
}

bool isRight(string& s) {
	stack<int> st;

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == '(') {
			st.push(c);
		}
		else {
			if (st.empty()) {
				return false;
			}
			else {
				st.pop();
			}
		}

	}
	return true;
}
string rev(string& s) {
	string ret = "";
	for (int i = 1;i<s.size()-1;i++) {
		ret.push_back(s[i] == ')' ? '(' : ')');
	}
	return ret;
}

string solution(string p) {
	
	if (p == "") return p;
	string ret;

	int sz = getBalance(p);
	string w = p.substr(0, sz);
	string u = p.substr(sz, p.size() - sz);

	string k = solution(u);
	if (isRight(w)) {
		ret = w + k;
	}
	else {
		ret = "("+k+")";
		ret += rev(w);
	}
	return ret;
}