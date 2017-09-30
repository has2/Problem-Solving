//BOJ
//ID : 11051 // dp
//2017/09/30
#include <cstdio>
#include <cstring>
int MOD = 10007;
int m,k,dp[1001][1001];

int sol(int n, int r) {

	if (r == 0 || r == n) return 1;
	if (r == 1) return n;


	int& ret = dp[n][r];
	if (ret != -1) return ret;

	return ret = (sol(n - 1, r - 1) + sol(n - 1, r))%MOD;

}

int main() {
	scanf("%d%d", &m,&k);
	memset(dp, -1, sizeof(dp));
	printf("%d", sol(m, k));
}