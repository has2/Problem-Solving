//BOJ
//ID : 10451 / DFS
//2017/07/26

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int adj[1001];
bool visited[1001];
int n,cnt;

void dfs(int s) {

	visited[s] = true;

	if (visited[adj[s]]) ++cnt;
	else dfs(adj[s]);
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &adj[i]);

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}
		printf("%d\n", cnt);
		memset(visited, 0, sizeof(visited));
	}
}

