#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		stack<pair<char,int>> S;
		string str;
		int len = 0;
		cin >> str;
		S.push(make_pair(0, -1));
		for (int i = 0; i < str.length(); i++) {

			char cur = str.at(i);
			
			if (cur == '[' || cur == '{' || cur == '(') {
				S.push(make_pair(cur, i));
			}
			else {

				char top_char = S.top().first;
				S.pop();
				if (S.empty()) {
					S.push(make_pair(cur, i));
				}
				else if ((cur == ']' && top_char == '[') ||
					(cur == '}' && top_char == '{') ||
					(cur == ')' && top_char == '(')) {
					len = max(i - S.top().second, len);
				}
				else {
					S.push(make_pair(cur, i));
				}
			}
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << len << endl;
	}

	return 0;
}