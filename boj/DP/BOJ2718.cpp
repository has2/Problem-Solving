// boj 2718 : DP / Tile
// 2017/07/19
#include <cstdio>
#include <vector>
using namespace std;

int main() {

	int c;
	scanf("%d", &c);
	while (c--) {

		int n;
		scanf("%d", &n);
		vector<int> d[5];
		for (int i = 0; i < 5; i++)
			d[i].resize(n + 3,0);

		d[0][0] = 1;
		d[0][1] = 1;
		d[0][2] = 5;
		d[1][2] = 1;
		d[2][2] = 1;
		d[3][2] = 1;
		d[4][2] = 1;

		for (int i = 3; i <= n; i++) {
			d[1][i] = d[2][i - 1];
			d[2][i] = d[1][i - 1] + d[0][i - 1];
			d[3][i] = d[4][i - 1] + d[0][i-2];
			d[4][i] = d[3][i - 1] + d[0][i-2];
			d[0][i] = d[3][i] + d[4][i] + d[1][i] + d[0][i - 1] + d[0][i-2];
		}

		printf("%d\n", d[0][n]);
	}

}
//
//#include <cstdio>
//int dp[1000][6];
//int main() {
//	dp[1][5] = 1;
//	dp[2][1] = 1;
//	dp[2][2] = 1;
//	dp[2][3] = 1;
//	dp[2][4] = 1;
//	dp[2][5] = 1;
//	for (int i = 3; i<100; ++i) {
//
//			dp[i][4] = dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3] + dp[i - 2][4] + dp[i - 2][5];
//		dp[i][5] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5];
//		dp[i][1] = dp[i][4] + dp[i - 1][1];
//		dp[i][3] = dp[i][4] + dp[i - 2][3];
//		dp[i][2] = dp[i][4] + dp[i - 1][2];
//
//	}
//	int t;
//	for (scanf("%d", &t); t; --t) {
//		int n;
//		scanf("%d", &n);
//		printf("%d",dp[n+2][4]);
//	}
//}
