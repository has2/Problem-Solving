#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, N, dp[1000][1000], a[1000];
int sol(int l, int r) {
	if (l == r) return (l + r + N % 2) % 2 == 0 ? 0 : a[l];
	int& ret = dp[l][r];
	if (ret != -1)return ret;
	if((l+r+N%2)%2) ret = max(a[l] + sol(l + 1, r), a[r] + sol(l, r - 1));
	else ret = min(sol(l + 1, r),sol(l, r - 1));
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);
		printf("%d\n", sol(0, N - 1));
	}
}