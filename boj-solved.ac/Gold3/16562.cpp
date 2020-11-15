#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int mxN = 1e4 + 1;
int N,M,K,cost[mxN];
vector<int> adj[mxN];
bool visit[mxN];
int dfs(int n) {
	visit[n] = 1;
	int ret = cost[n];
	for (auto nxt : adj[n]){
		if (!visit[nxt]) ret = min(ret,dfs(nxt));
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%d", &cost[i]);

	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) sum += dfs(i);
	}
	
	if (sum <= K) printf("%d", sum);
	else puts("Oh no");
}