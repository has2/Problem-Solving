//BOJ
//ID : 11724 / DFS
//2017/08/01

#include <cstdio>
#include <vector>

int n, m, visit[1001],cnt;
std::vector<int> adj[1001];

void dfs(int s) {

	visit[s] = 1;
	for (int to : adj[s]) 
		if (!visit[to]) dfs(to);
	
}

int main() {

	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}