//BOJ
//ID : 11052 // dp
//2017/09/24

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a[1001],cache[1001];
int sol(int m) {

	if (m == 0) return 0;

	int& ret = cache[m];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i <= n; i++) {
		if (m - i >= 0)
			ret = max(ret, a[i] + sol(m - i));
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	memset(cache, -1, sizeof(cache));
	printf("%d", sol(n));
}
