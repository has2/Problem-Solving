//BOJ
//ID : 14501 / DP
//2017/08/24

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,T[16], P[16],cache[16];

int sol(int day) {

	if (day - 1 > n) return -1000;
	if (day - 1 == n) return 0;

	int& ret = cache[day];

	if (ret != -1) return ret;
	ret = 0;
	return ret = max(sol(day + 1), sol(day + T[day]) + P[day]);
}

int main() {
	scanf("%d", &n);

	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &T[i], &P[i]);

	printf("%d", sol(0));
}







