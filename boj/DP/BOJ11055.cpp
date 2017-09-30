//BOJ
//ID : 11055 // dp
//2017/09/30
#include <cstdio>
#include <cstring>
#include <algorithm>
int n,a[1001],dp[1001];

int sol(int p) {

	if (p == n) return a[p];

	int& ret = dp[p];
	if (ret != -1) return ret;
	
	ret = a[p];
	for (int i = p + 1; i <= n; i++)
		if (a[p] < a[i]) ret = std::max(ret, a[p] + sol(i));

	return ret;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d", sol(0));
}