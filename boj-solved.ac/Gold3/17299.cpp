#include <cstdio>
const int mxN = 1e6 + 1;
int N, a[mxN],cnt[mxN],dp[mxN];
int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	dp[N - 1] = -1;
	for (int i = N - 2; i >= 0; i--) {
		int j = i+1;
		while (1) {
			if (cnt[a[i]] < cnt[a[j]]) {
				dp[i] = j;
				break;
			}
			j = dp[j];
			if (j == -1) {
				dp[i] = -1;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) printf("%d ", dp[i]==-1 ? -1 : a[dp[i]]);
}