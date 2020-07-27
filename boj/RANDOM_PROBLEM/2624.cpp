#include <cstdio>

int T, K, P[1001], cnt[1001],dp[10001];

int main() {
	scanf("%d%d", &T, &K);
	for (int i = 0; i < K; i++) scanf("%d%d", &P[i], &cnt[i]);
	dp[0] = 1;
	for (int i = 0; i < K; i++) {
		for (int j = T; j >= 1; j--) {
			int sum = 0;
			for (int k = 0; k < cnt[i]; k++) {
				sum += P[i];
				if (j - sum >= 0 && dp[j-sum] > 0) dp[j] += dp[j - sum];
			}
		}
	}
	printf("%d",dp[T]);
}