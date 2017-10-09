//SW Expert
//ID : 2105 // backtracking
//2017/10/09

#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, c, a[11][11];

int getMax(int y, int x) {
	
	int maxsq=0;
	int possible = (1 << m) - 1;
	for (int mask = 0; mask <= possible; mask++) {
		int sum = 0, sq = 0;
		for (int i = 0; i < m; i++) {
			if ((1 << i) & mask) {
				sum += a[y][x + i];
				sq += a[y][x + i] * a[y][x + i];
			}
		}
		if (sum <= c) maxsq = max(sq, maxsq);
	}
	return maxsq;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int testcase = 1; testcase <= tc; testcase++) {
		scanf("%d%d%d", &n, &m, &c);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);

		int ret = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - m + 1; j++) {
				
				int v1 = getMax(i, j);

				int v2;
				for (int k = j + m; k <= n - m + 1; k++) {
					if (k + m - 1 > n) break;
					
					v2 = getMax(i, k);
					if (ret < v2 + v1) ret = v1 + v2;		
				}

				for (int k = i + 1; k <= n; k++) {
					for (int l = 1; l <= n - m + 1; l++) {
						v2 = getMax(k, l);
						if (ret < v2 + v1) ret = v2 + v1;
					}
				}
			}
		}
		printf("#%d %d\n", testcase, ret);
	}
}