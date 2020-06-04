#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, bcnt[101], cost[101], d[101][10001];

int sol(int n, int curCost) {

	if (n > N) return 0;
	int& ret = d[n][curCost];
	if (ret != -1) return ret;
	ret = sol(n + 1, curCost);
	if (curCost - cost[n] >= 0) {
		ret = max(ret, sol(n + 1, curCost - cost[n]) + bcnt[n]);
	}
	return ret;
}

int main() {

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &bcnt[i]);
	for (int i = 1; i <= N; i++) scanf("%d", &cost[i]);

	memset(d, -1, sizeof(d));
	for (int i = 1;; i++) {
		int ret = sol(1, i);
		if (ret >= M) {
			printf("%d", i);
			return 0;
		}
	}
}