#include <cstdio>

long long dp[101][21];
int main(void) {
	int N,num;
	long long ans = 0;
	scanf("%d", &N);
	scanf("%d", &num);
	dp[1][num] = 1;

	for (int i = 2; i <= N; i++) {
		scanf("%d", &num);
		if (N == i) {
			ans = dp[N - 1][num];
			break;
		}

		for (int k = 0; k <= 20; k++) {
			if (k + num <= 20)
				dp[i][k + num] += dp[i - 1][k];
			if (k - num >= 0)
				dp[i][k - num] += dp[i - 1][k];
		}
	}
	printf("%lld\n", ans);
	
}