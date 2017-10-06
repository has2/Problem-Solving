//BOJ
//ID : 4179 // stack
//2017/10/04

#include <string>
#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
string str;
int main() {

	for(int k=1; ;k++){
		int ret = 0;
		cin >> str;
		if (str[0] == '-') return 0;

		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if (ch == '{') s.push(ch);
			else {
				if (s.empty()) s.push(ch);
				else if (s.top() == '{') s.pop();
				else s.push(ch);
			}
		}

		while (!s.empty()) {
			char a = s.top(); s.pop();
			char b = s.top(); s.pop();
			if (a != b) ret += 2;
			else ret += 1;
		}
		cout << k << ". " << ret << endl;
	}
}