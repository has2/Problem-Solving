#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <cstring>
using namespace std;


int N, K, V[1001],E;
bool hasOut[1001], hasIn[1001];
int dist[1001];
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		vector<pair<int, int>> adj[1001];
		memset(hasOut, 0, sizeof(hasOut));
		memset(hasIn, 0, sizeof(hasIn));
		memset(dist, 0, sizeof(dist));

		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++) scanf("%d", &V[i]);
		
		for (int i = 1; i <= K; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back({ V[a],b });
			hasOut[a] = 1;
			hasIn[b] = 1;
		}
		scanf("%d",&E);
		vector<int> start;
		for (int i = 1; i <= N; i++) {
			if (hasIn[i] == 0) start.push_back(i);
		}
		

		int ans = 0;
		for (int i = 0; i < start.size(); i++) {
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			pq.push({ 0,start[i] });
			for (int i = 1; i <= N; i++) dist[i] = -987654321;
			dist[start[i]] = 0;
			while (!pq.empty()) {

				auto p = pq.top(); pq.pop();
				int cost = p.first;
				int here = p.second;
				if (cost < dist[here]) continue;

				//dist[here] = cost;

				for (auto a : adj[here]) {
					int next = a.second;
					int ncost = a.first;
					if (dist[next] < dist[here] + ncost) {
						dist[next] = dist[here] + ncost;
						pq.push({ dist[next],next });
					}
				}
			}
			//printf("ret : %d\n", dist[E] + V[E]);
			ans = max(ans, dist[E] + V[E]);
		}
		printf("%d\n", ans);
	}
}