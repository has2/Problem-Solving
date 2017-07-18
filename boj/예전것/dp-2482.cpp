#include <cstdio>

long long dp[1001][1001][3];

int main(void)
{
	int N,K; scanf("%d%d",&N,&K);
	dp[2][1][1] = 2; 
	dp[3][1][1] = 3; dp[3][2][2] = 1;
	dp[4][1][1] = 4; dp[4][2][2] = 1; dp[4][2][1] = 2;
	dp[5][1][1] = 5; dp[5][2][1] = 5; dp[5][2][2] = 1; dp[5][3][2] = 1;

	for (int i = 6; i <= N; i++)
	{
		dp[i][1][1] = i;
		for (int j = 2; j <= K; j++)
		{
			dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 3][j - 1][1] + dp[i - 3][j - 1][2] )% 1000000003;
			if (j == 2) {
				dp[i][j][2] = 1; continue;
			}
			dp[i][j][2] = (dp[i - 4][j - 2][1] + dp[i - 4][j - 2][2])% 1000000003;
		}
 	}
	printf("%lld", dp[N][K][1]);
}