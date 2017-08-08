//BOJ
//ID : 9466 / DFS
//2017/08/01
// cycle 판별시 discover 배열 이용 

#include <cstdio>
#include <cstring>
using namespace std;

int adj[100001], disc[100001], n;
int cnt, st;

int dfs(int s) {

	disc[s] = cnt++;

	if (disc[adj[s]] == 0)
		return dfs(adj[s]);
	else if (st <= disc[adj[s]] && disc[adj[s]] <= disc[s])
		return disc[s] - disc[adj[s]] + 1;
	else
		return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {

		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &adj[i]);

		int total = 0, ret;
		cnt = 1, st = 1;
		for (int i = 1; i <= n; i++) {
			if (!disc[i]) {
				ret = dfs(i);
				if (ret > 0) total += ret;
				st = cnt;
			}
		}
		printf("%d\n", n - total);
		memset(disc, 0, sizeof(disc));
		memset(adj, 0, sizeof(adj));
	}
}
