#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001][3];
int main(void) {

	int N,m=987654321;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int r, g, b;
		scanf("%d%d%d", &r, &g, &b);
		dp[i][0] = r + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = g + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = b + min(dp[i - 1][0], dp[i - 1][1]);
	}
	for (int i = 0; i < 3; i++)
		m = min(m, dp[N][i]);
	printf("%d\n", m);
}