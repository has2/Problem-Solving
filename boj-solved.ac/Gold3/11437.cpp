#include <cstdio>
#include <vector>
using namespace std;
int N, M, parent[50001][17];
int depth[50001];
vector<int> adj[50001];

void dfs(int cur,int dep) {
	depth[cur] = dep;
	for (auto next : adj[cur]) {
		if (depth[next] == 0) {
			parent[next][0] = cur;
			dfs(next,dep + 1);
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 1);

	for (int i = 1; i < 17; i++) {
		for (int j = 2; j <= N; j++) {
			if(parent[j][i-1] != 0)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	scanf("%d", &M);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);

		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for (int j = 0; diff; j++) {
			if (diff % 2) u = parent[u][j];
			diff /= 2;
		}
		if (u != v) {
			for (int i = 16; i >= 0; i--) {
				if (parent[u][i] && parent[u][i] != parent[v][i]) {
					u = parent[u][i];
					v = parent[v][i];
				}
			}
			u = parent[u][0];
		}

		printf("%d\n", u);
	}
}