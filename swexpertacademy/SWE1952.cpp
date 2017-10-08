//SW Expert
//ID : 1952 // dp
//2017/10/08

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,cost[4],a[13], cache[13],INF=987654321;

int sol(int cur) {

	if (cur > 12) return 0;

	int& ret = cache[cur];
	if (ret != -1) return ret;

	ret = INF;
	ret = min(ret, a[cur] * cost[0] + sol(cur + 1));
	ret = min(ret, cost[1] + sol(cur + 1));
	ret = min(ret, cost[2] + sol(cur + 3));

	return ret;
}


int main() {

	int tc; scanf("%d", &tc);
	for (int k = 1; k <= tc; k++) {

		for (int i = 0; i < 4; i++)
			scanf("%d", &cost[i]);

		for (int i = 1; i <= 12; i++)
			scanf("%d", &a[i]);

		memset(cache, -1, sizeof(cache));
		printf("#%d %d\n",k,min(cost[3],sol(1)));
	}
}