//BOJ
//ID : 2167 // dp
//2017/10/05

#include <cstdio>
int n,m,a[301][301],t,c;
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &t);
			a[i][j] = t + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	
	scanf("%d", &c);
	while (c--) {
		int y1, x1, y2, x2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		printf("%d\n", a[y2][x2] - a[y1 - 1][x2] - a[y2][x1 - 1] + a[y1 - 1][x1 - 1]);
	}
}