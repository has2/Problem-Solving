#include <cstdio>

const int mod = 10007;

int dp[1001];
int main(void) {
	int N;
	scanf("%d", &N);

	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%mod;
	}
	printf("%d\n", dp[N]);
}