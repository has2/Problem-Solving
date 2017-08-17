//BOJ
//ID : 1613 / Floyd-Warshall
//2017/08/17

#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int n, k, s, dist[401][401];

int main() {
	scanf("%d%d", &n, &k);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j ? 0 : INF;

	while (k--) {
		int a, b;
		scanf("%d%d", &a, &b);
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	scanf("%d", &s);
	while (s--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (dist[a][b] == INF && dist[b][a] == INF) puts("0");
		else if (dist[a][b] != INF) puts("-1");
		else puts("1");
	}
}






