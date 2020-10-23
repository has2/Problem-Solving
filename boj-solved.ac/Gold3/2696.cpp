#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
int t, N, v;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		priority_queue<int> maxH;
		priority_queue<int, vector<int>, greater<int>> minH;
		vector<int> ans;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &v);
			if (i == 1) {
				maxH.push(v);
				ans.push_back(v);
				continue;
			}
			if (i % 2) {
				if (maxH.top() >= v) maxH.push(v);
				else {
					minH.push(v);
					maxH.push(minH.top()), minH.pop();
				}
				ans.push_back(maxH.top());
			}
			else {
				if (maxH.top() < v) minH.push(v);
				else {
					maxH.push(v);
					minH.push(maxH.top()), maxH.pop();
				}
			}
		}
		printf("%d\n", ans.size());
		for (int i = 1; i <= ans.size(); i++) {
			printf("%d ", ans[i-1]);
			if (i == ans.size() || i % 10 == 0) printf("\n");
		}
	}
}