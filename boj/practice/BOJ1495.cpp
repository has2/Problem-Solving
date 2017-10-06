//BOJ
//ID : 1495 // dp
//2017/10/07

#include <cstdio>
int n, s, m, v[100],ret=-1;
bool dp[100][1001];

int main() {
	scanf("%d%d%d", &n, &s, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	if (s + v[0] <= m) dp[0][s + v[0]] = 1;
	if (s - v[0] >= 0) dp[0][s - v[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j + v[i] <= m) dp[i][j + v[i]] = 1;
				if (j - v[i] >= 0) dp[i][j - v[i]] = 1;
			}
		}
	}

	for (int j = 0; j <= m; j++)
		if (dp[n - 1][j]) ret = j;

	printf("%d", ret);
}