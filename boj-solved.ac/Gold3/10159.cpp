#include <cstdio>
#include <algorithm>
int N, M,dist[101][101],INF = 987654321,a, b;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) dist[i][j] = i == j ? 0 : INF;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		dist[a][b] = 1;
	}
	for (int k = 1; k <= N; k++) 
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) 
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) if (dist[i][j] == INF && dist[j][i] == INF) cnt++;
		printf("%d\n", cnt);
	}
}