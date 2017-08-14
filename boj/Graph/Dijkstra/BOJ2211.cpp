//BOJ
//ID : 2211 / Dijkstra
//2017/08/13

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;
int n, m, dist[1001];
vector<pair<int, int>> adj[1001];

int main() {

	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}

	fill(dist + 1, dist + 1 + n, INF);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	vector<int> par(n + 1);
	par[1] = 1;

	while (!pq.empty()) {

		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (cost > dist[here]) continue;

		for (auto there : adj[here]) {
			int next = there.first;
			int nextDist = there.second + cost;
			if (nextDist < dist[next]) {
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
				par[next] = here;
			}
		}
	}
	
	printf("%d\n", n - 1);
	for (int i = 2; i <= n; i++) 
		printf("%d %d\n", i, par[i]);
	
}

