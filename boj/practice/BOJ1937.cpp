//BOJ
//ID : 1937 // dp
//2017/09/22

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, map[502][502], cache[502][502];

int sol(int y, int x) {

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (!map[ty][tx] || map[ty][tx] <= map[y][x]) continue;
		ret = max(ret, 1 + sol(ty, tx));
	}
	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);

	memset(cache, -1, sizeof(cache));

	int k = 0;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			k = max(k, sol(y, x));

	printf("%d", k);
}