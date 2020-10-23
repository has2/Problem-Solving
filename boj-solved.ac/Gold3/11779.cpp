#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct P {
	int cost, v;
};
int n, m, dist[1001], s, e,INF=987654321;
vector<P> adj[1001];
int parent[1001];
struct cmp {
	bool operator()(P& a, P& b) {
		return a.cost > b.cost;
	}
};

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ c,b });
	}
	scanf("%d%d", &s, &e);
	priority_queue<P, vector<P>, cmp> pq;

	for (int i = 1; i <= n; i++) dist[i] = INF;

	dist[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty()) {

		auto p = pq.top(); pq.pop();
		int cost = p.cost;
		int here = p.v;

		if (cost > dist[here]) continue;
		for (auto t : adj[here]) {
			int c = t.cost;
			int there = t.v;
			if (dist[there] > dist[here] + c) {
				
				dist[there] = dist[here] + c;
				parent[there] = here;
				pq.push({ dist[there],there});
			}
		}
	}
	int cur = e;
	vector<int> ans;
	while (1) {
		ans.push_back(cur);
		if (cur == s) break;
		cur = parent[cur];
	}
	printf("%d\n%d\n", dist[e], ans.size());
	for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
}