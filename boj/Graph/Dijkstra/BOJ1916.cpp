//BOJ
//ID : 1916 / Dijkstra
//2017/08/13

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = 9876543;

int n, m, dist[1001],S,E;
vector<pair<int,int>> adj[1001];

int main() {

	scanf("%d%d", &n, &m);
	fill(dist + 1, dist + n+1, INF);

	while (m--) {
		int u, v,c;
		scanf("%d%d%d", &u, &v,&c);
		adj[u].push_back(make_pair(v, c));
	}
	scanf("%d%d", &S, &E);

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, S));
	dist[S] = 0;
	
	while (!pq.empty()) {

		pair<int, int> here = pq.top(); pq.pop();

		int v = here.second;
		int cost = -here.first;

		if (cost > dist[v]) continue;

		for (auto there : adj[v]) {
			int next = there.first;
			int nextDist = there.second+cost;

			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist,next));
			}
		}
	}

	printf("%d\n", dist[E]);
}

