//BOJ
//ID : 2662 // dp
//2017/10/03

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, a[301][20], cache[20][301], t;

int sol(int cur, int rem) {

	if (rem == 0) return 0;
	if (cur >= k) return 0;

	int& ret = cache[cur][rem];
	if (ret != -1) return ret;

	for (int i = 0; i <= rem; i++)
		ret = max(ret, a[i][cur] + sol(cur + 1, rem - i));

	return ret;
}

int main() {

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		for (int j = 0; j < k; j++) scanf("%d", &a[i][j]);
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", sol(0, n));

	int e = cache[0][n];
	int rm = n;
	for (int i = 0; i < k; i++) {
		int res = 0;
		for (int j = 0; j <= n; j++) {
			if (e == a[j][i] + (cache[i + 1][rm - j] == -1 ? 0 : cache[i + 1][rm - j])) {
				res = j;
				e = cache[i + 1][rm - j];
				rm -= j;
				break;
			}
		}
		printf("%d ", res);
	}
}