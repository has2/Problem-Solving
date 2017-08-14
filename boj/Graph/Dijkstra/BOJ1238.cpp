//BOJ
//ID : 1238 / Dijkstra
//2017/08/13

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;

int n,m,x,dist[1001];
vector<pair<int, int>> adj[2][1001];

int main() {

	scanf("%d%d%d", &n, &m, &x);

	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[0][u].push_back(make_pair(v, c));
		adj[1][v].push_back(make_pair(u, c));
	}
	vector<int> ret(n + 1);

	for (int i = 0; i < 2; i++) {

		fill(dist+1, dist +1+n, INF);

		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, x));
		dist[x] = 0;
		while (!pq.empty()) {

			int here = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if (cost > dist[here]) continue;

			for (auto there : adj[i][here]) {
				int next = there.first;
				int nextDist = there.second + cost;
				if (dist[next] > nextDist) {
					dist[next] = nextDist;
					pq.push(make_pair(-nextDist, next));
				}

			}
		}
		for (int k = 1; k <= n; k++)
			ret[k] += dist[k];
	}
	int ans = -1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, ret[i]);

	printf("%d", ans);
}

