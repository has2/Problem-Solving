//BOJ
//ID : 10157 // dfs
//2017/10/06

#include <cstdio>
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m,k;
bool map[1001][1001];

void dfs(int y, int x, int d, int cnt) {

	if (cnt == k) {
		printf("%d %d", x, y);
		return;
	}

	map[y][x] = 1;
	int ty = y + dy[d], tx = x + dx[d];

	if (ty<1 || tx<1 || ty > n || tx > m || map[ty][tx]) {
		int nd = (d + 1) % 4;
		dfs(y+dy[nd],x+dx[nd], nd, cnt + 1);
	}
	else dfs(ty, tx, d, cnt + 1);
}

int main() {
	scanf("%d%d%d", &m, &n,&k);
	if (k > n*m) puts("0");
	else dfs(1, 1, 0, 1);
}