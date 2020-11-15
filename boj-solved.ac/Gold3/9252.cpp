#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001],n,m;
int main() {

	string a, b;
	cin >> a >> b;
	n = b.size();
	m = a.size();
	for (int i = 1; i <= n; i++) {
		char c = b[i - 1];
		for (int j = 1; j <= m; j++) {
			char d = a[j - 1];
			if (c == d) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[n][m]);
	
	if (!dp[n][m]) return 0;
	int y = n;
	int x = m;
	string ret;
	while (dp[y][x]) {
		if (b[y - 1] == a[x - 1]) {
			ret = b[y - 1] + ret;
			y--;
			x--;
		}
		else if (dp[y][x] == dp[y - 1][x]) y--;
		else x--;
	}
	cout << ret;
}