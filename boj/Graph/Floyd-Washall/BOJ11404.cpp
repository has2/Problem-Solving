#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int dis[101][101];
int main(void) {
	
	int N, M,a,b,c;
	scanf("%d%d",&N, &M);
	for (int i = 1; i <= N; i++) {
		fill(dis[i] + 1, dis[i] + 101, INF);
		dis[i][i] = 0;
	}

	while (M--) {
		scanf("%d%d%d", &a, &b, &c);
		if(dis[a][b] > c)
		dis[a][b] = c;
	}

	for (int k = 1; k <= N; k++) 
		for (int n = 1; n <= N; n++) 
			for (int m = 1; m <= N; m++) {
				if (dis[n][m] > dis[n][k] + dis[k][m])
					dis[n][m] = dis[n][k] + dis[k][m];
			}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", dis[i][j]);
		printf("\n");
	}

		
}