//BOJ
//ID : 11066 // dp
//2017/10/01
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
int n,a[501],cache[501][501],sum[501];

int sol(int l, int r) {

	if (l == r) return 0;
	if (l + 1 == r) return a[l] + a[r];

	int& ret = cache[l][r];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = l; i < r; i++) 
		ret = min(ret, sol(l, i) + sol(i + 1, r)+ sum[r] - sum[l - 1]);
	
	return ret;
}


int main() {

	int c;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		printf("%d\n", sol(1, n));
	}
}