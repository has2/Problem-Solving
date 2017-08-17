//BOJ
//ID : 11657 / Bellman-ford
//2017/08/15

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n, m, dist[501];
vector<pair<int, int>> adj[501];

int main() {

	scanf("%d%d", &n, &m);

	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
	}

	fill(dist + 1, dist + 1 + n, INF);
	dist[1] = 0;
	bool isCycle;

	for (int i = 1; i <= n; i++) {
		isCycle = false;
		for (int j = 1; j <= n; j++) {
			if (dist[j] == INF) continue;

			for (auto there : adj[j]) {
				int next = there.first;
				int nextDist = there.second + dist[j];
				if (dist[next] > nextDist) {
					isCycle = true;
					dist[next] = nextDist;
				}
			}
		}
	}

	if (isCycle) puts("-1");
	else
		for (int i = 2; i <= n; i++)
			printf("%d\n", dist[i] == INF ? -1 : dist[i]);
}






