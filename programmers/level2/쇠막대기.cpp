#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
	int answer = 0;

	stack<int> s;

	for (int i = 0; i < arrangement.size(); i++) {
		char c = arrangement[i];
		if (c == '(') s.push(i);
		else {
			if (i - s.top() == 1) {
				answer +=(s.size()-1);
			}
			else {
				answer += 1;
			}
			s.pop();
		}
	}
	return answer;
}