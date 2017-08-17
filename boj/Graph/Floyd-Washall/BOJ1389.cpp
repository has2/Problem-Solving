//BOJ
//ID : 1389 / Floyd-Warshall
//2017/08/17

#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n, m, dist[101][101];

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j ? 0 : INF;

	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ansv = INF, ansi = 1;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++)
			if (i != j) sum += dist[i][j];

		if (ansv > sum) {
			ansi = i;
			ansv = sum;
		}
	}
	printf("%d", ansi);
}






