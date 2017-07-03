#include <cstdio>
#include <algorithm>
using namespace std;

unsigned long long dp[91][2];
int main(void) {
	int N;
	scanf("%d", &N);
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][1] = dp[i - 1][0];
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
	}
	printf("%llu", dp[N][0] + dp[N][1]);
}