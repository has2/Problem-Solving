#include <cstdio>
#include <cstring>
int cache[31][31];

int main() {

	int tc;
	scanf("%d", &tc);
	
	while (tc--) {

		int n, m, cnt = 0;
		scanf("%d%d", &n, &m);

		for (int i = 1; i <= m; i++)
			cache[1][i] = 1;

		for (int i = 2; i <= n; ++i) {
			for (int j = i; j <= m; ++j) {
				for (int k = 1; k < j; ++k)
					cache[i][j] += cache[i - 1][k];
			}
		}

		for (int i = n; i <= m; i++)
			cnt += cache[n][i];

		printf("%d\n", cnt);
		memset(cache, 0, sizeof(cache));
	}
}