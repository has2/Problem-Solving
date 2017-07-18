#include <cstdio>
#include <algorithm>
#include <cstring>
const int mod = 1000000007;
int cache[101],n;

int sol(int m) {

	if (m == 2) return cache[m] = 2;
	if (m == 1) return cache[m] = 1;

	int& ret = cache[m];
	if (ret != -1) return ret;

	return ret = (sol(m - 1) + sol(m - 2))%mod;

}

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		printf("%d\n", sol(n));
	}
}