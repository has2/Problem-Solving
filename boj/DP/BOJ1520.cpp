//BOJ
//ID : 1520 // dp
//2017/10/14

#include <cstdio>
#include <cstring>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m, map[500][500], cache[500][500];

int sol(int y, int x) {

	if (y == n - 1 && x == m - 1) return 1;

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	ret = 0;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m || map[ty][tx] >= map[y][x])	continue;
		ret += sol(ty, tx);
	}
	return ret;
}

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &map[i][j]);

	memset(cache, -1, sizeof(cache));
	printf("%d\n", sol(0, 0));
}