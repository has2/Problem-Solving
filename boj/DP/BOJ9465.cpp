//BOJ
//ID : 9465 // dp
//2017/09/30
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a[2][100000],cache[3][100000];

int sol(int k, int cur) {
	
	if (cur >= n) return 0;

	int& ret = cache[k][cur];
	if (ret != -1) return ret;

	if (k < 2) ret = a[k][cur] + max(sol(1 - k, cur + 1), sol(2, cur + 1));
	else {
		ret = max(sol(0, cur + 1), sol(1, cur + 1));
		ret = max(ret, sol(2, cur + 1));
	}
	return ret;
}

int main() {

	int c;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);

		memset(cache, -1, sizeof(cache));
		int res = max(sol(0, 0), sol(1, 0));
		printf("%d\n", max(res, sol(2, 0)));
	}
}