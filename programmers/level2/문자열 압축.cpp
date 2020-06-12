#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sol(string& s, int len) {

	int ret = 0;

	int cnt = 1;
	for (int i = len; i < s.size() ; i += len) {
		string s1 = s.substr(i-len, len);
		string s2 = s.substr(i, len);
		//cout << s1 << "," << s2 << endl;
		if (s1 == s2) {
			cnt++;
		}
		else {
			ret += len;
			if (cnt != 1) ret += to_string(cnt).size();
			cnt = 1;
		}
		if (i + len >= s.size()) {
			ret += s2.size();
			if (cnt != 1) ret += to_string(cnt).size();
		}
		//cout << ret << endl;

	}
	return ret;
}

int solution(string s) {
	if (s.size() == 1) return 1;

	int answer = 10000;

	for (int i = 1; i <= s.size() / 2; i++) {
		answer = min(answer,sol(s, i));
	}

	return answer;
}

int main() {

	string cc = "a";
	string a = "abcdefgkc";
	string b = "ababcdcdababcdcd";
	string s = "abcabcabcabcdededededede";
	string c = "abcabcdede";
	string x = "xababcdcdababcdcd";
	cout << solution(cc);

}