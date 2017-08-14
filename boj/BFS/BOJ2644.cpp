//BOJ
//ID : 2644 / BFS
//2017/08/11

#include <cstdio>
#include <queue>

using namespace std;

int n, m,s,e,cost[101];
vector<int> adj[101];

int main() {

	scanf("%d %d %d %d", &n,&s,&e,&m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> Q;
	Q.push(s);

	while (!Q.empty()) {
		
		int here = Q.front(); Q.pop();

		for (int there : adj[here]) {
			if (!cost[there]) {
				cost[there] = cost[here] + 1;
				Q.push(there);
			}
		}
	}
	if (!cost[e]) cost[e] = -1;
	printf("%d", cost[e]);
}