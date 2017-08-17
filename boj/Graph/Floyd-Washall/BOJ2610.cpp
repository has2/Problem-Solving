//BOJ
//ID : 2610 / Floyd-Warshall
//2017/08/17

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
int n, m, dist[101][101], visit[101], cnt;
vector<int> component[100];
void dfs(int s) {
	visit[s] = 1;
	component[cnt - 1].push_back(s);

	for (int i = 1; i <= n; i++)
		if (dist[s][i] == 1 && !visit[i]) dfs(i);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;

	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}

	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	printf("%d\n", cnt);
	vector<int> ret;
	for (int c = 0; c < cnt; c++) {

		int repv = INF;
		int repi;
		for (int i : component[c]) {
			int m = -1;
			for (int j : component[c])
				m = max(m, dist[i][j]);

			if (repv > m) {
				repi = i;
				repv = m;
			}
		}
		ret.push_back(repi);
	}
	sort(ret.begin(), ret.end());
	for (int v : ret)
		printf("%d\n", v);
}






