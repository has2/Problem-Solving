#include <cstdio>

int N, dist[21][21];
bool del[21][21];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &dist[i][j]);

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (k == i || k == j) continue;
				if (dist[i][j] == dist[i][k] + dist[k][j]) del[i][j] = 1;
				else if (dist[i][j] > dist[i][k] + dist[k][j]) {
					puts("-1");
					return 0;
				}
			}
		}
	}
	int sum = 0;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			if (!del[i][j] && !del[j][i]) sum += dist[i][j];
		}

	printf("%d", sum / 2);
}