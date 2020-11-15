#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[101][101][101],n,m,k;
int main() {
	string a, b,t;
	cin >> a >> b >> t;
	n = b.size();
	m = a.size();
	k = t.size();
	for (int i = 1; i <= n; i++) {
		char c = b[i - 1];
		for (int j = 1; j <= m; j++) {
			char d = a[j - 1];
			for (int l = 1; l <= k; l++) {
				char e = t[l - 1];
				if (c == d && e == c) dp[i][j][l] = dp[i - 1][j - 1][l-1] + 1;
				else dp[i][j][l] = max(max(dp[i - 1][j][l], dp[i][j - 1][l]),dp[i][j][l-1]);
			}
		}
	}
	printf("%d\n", dp[n][m][k]);
}