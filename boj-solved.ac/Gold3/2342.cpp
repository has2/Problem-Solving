#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int mxN = 1e5+1,INF=9e8;
int a[mxN], dp[mxN][5][5],N;
int power(int from, int to) {
	int diff = abs(from - to);
	int ret = 3;
	if (from == 0) ret = 2;
	else if (diff == 0) ret = 1;
	else if (diff == 2) ret = 4;
	return ret;
}
int sol(int cur, int l, int r) {

	if (cur == N) return 0;
	int& ret = dp[cur][l][r];
	if (ret != -1) return ret;

	int next = a[cur];
	int lton = power(l, next);
	int rton = power(r, next);
	if (l == next) ret = lton + sol(cur + 1, next, r);
	else if (r == next) ret = rton + sol(cur + 1, l, next);
	else  ret = min(lton + sol(cur + 1, next, r), rton + sol(cur + 1, l, next));
	return ret;
}
int main() {
	int p;
	for (int i = 0;; i++) {
		scanf("%d", &p);
		N = i;
		if (p == 0) break;
		a[i] = p;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", sol(0, 0, 0));
}