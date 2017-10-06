//BOJ
//ID : 2156 // dp
//2017/10/05

#include <cstdio>
#include <cstring>
#include <algorithm>
int n, a[10000], cache[3][10000];

int sol(int k, int cur) {

	if (cur >= n) return 0;
	int& ret = cache[k][cur];
	if (ret != -1) return ret;

	ret = sol(0, cur + 1);
	if (k < 2) ret = std::max(a[cur] + sol(k + 1, cur + 1), ret);
	
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", sol(0, 0));
}