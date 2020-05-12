#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	int len = prices.size();
	vector<int> answer(len);
	stack<int> s;
	s.push(0);
	for (int i = 1; i < len; i++) {
		
		while (!s.empty()) {
			int top = s.top();
			if (prices[top] > prices[i]) {
				answer[top] = i - top;
				s.pop();
			}
			else {
				break;
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		int top = s.top();
		answer[top] = len - 1 - top;
		s.pop();
	}
	return answer;
}