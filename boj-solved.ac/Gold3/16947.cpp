#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> adj[3001];
int n, par[3001];
bool visit[3001], isCycle[3001],ok;
void dfs(int cur) {
	if (ok) return;
	visit[cur] = 1;
	for (auto v : adj[cur]) {
		if (ok) return;
		if (!visit[v]) {
			par[v] = cur;
			dfs(v);
		}
		else if (par[cur] && par[cur] != v) {
			ok = 1;
			int t = cur;
			isCycle[t] = 1;
			while (t != v) {
				t = par[t];
				isCycle[t] = 1;
			}
			return;
		}
	}
}

int dfs2(int cur,int k) {
	if (isCycle[cur]) {
		return k;
	}
	visit[cur] = 1;
	for (auto v : adj[cur]) {
		if (!visit[v]) {
			int ret = dfs2(v, k + 1);
			if (ret != -1) return ret;
		}
	}
	return -1;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (isCycle[i]) {
			printf("%d ", 0);
			continue;
		}
		memset(visit, 0, sizeof(visit));
		printf("%d ", dfs2(i, 0));
	}
}