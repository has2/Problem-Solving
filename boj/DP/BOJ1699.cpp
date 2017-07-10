#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int m,cache[100001],sq[400];

int sol(int n) {

	if (n == 0) return 0;

	int& ret = cache[n];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int i = 1; i < m; i++) {
		if (n - sq[i] < 0) break;
		ret = min(ret, sol(n-sq[i]) + 1);
	}
	return cache[n] = ret;

}

int main(void) {

	int n;
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (m = 1; m*m <= n; m++)
		sq[m] = m*m;

	printf("%d\n", sol(n));
}
