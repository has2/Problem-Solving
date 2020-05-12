#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {

	string answer = "";

	while (n > 0) {

		int k = n % 3;
		n /= 3;
		if (k == 0) {
			answer.push_back(4 + '0');
			n -= 1;
		}
		else {
			answer.push_back(k + '0');
		}

		
	}
	reverse(answer.begin(), answer.end());
	return answer;
}