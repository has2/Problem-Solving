#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> ans(seq.size());
		stack<int> a;
		for (int i = 0; i < seq.size(); i++) {
			char c = seq[i];

			if (c == '(') {
				if (a.empty()) a.push(0);
				else a.push(1 - a.top());
				ans[i] = a.top();
			}
			else {
				ans[i] = a.top();
				a.pop();
			}
		}
		return ans;
	}
};