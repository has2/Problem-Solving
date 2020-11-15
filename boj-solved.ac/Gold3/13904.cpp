#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map<int, vector<int>> m;
int N,ans;
int main() {
	scanf("%d", &N);
	int md = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		md = max(md, a);
		m[a].push_back(b);
	}
	priority_queue<int> pq;
	for (int i = md; i >= 1; i--) {
		auto v = m[i];
		for (auto w : v) pq.push(w);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%d", ans);
}