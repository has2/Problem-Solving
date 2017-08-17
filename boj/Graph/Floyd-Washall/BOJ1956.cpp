//BOJ
//ID : 1956 / Floyd-Warshall
//2017/08/17

#include <cstdio>
#include <algorithm>
const int INF = 987654321;
int v, e, dist[401][401];

int main() {
	scanf("%d%d", &v, &e);
	
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			dist[i][j] = INF;

	while (e--) {
		int a, b,c;
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

	int ret = INF;
	for (int i = 1; i <= v; i++)
		ret = std::min(ret, dist[i][i]);

	if (ret == INF) puts("-1");
	else printf("%d", ret);
}






