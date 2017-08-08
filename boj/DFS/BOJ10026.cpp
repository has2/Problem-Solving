//BOJ
//ID : 10026 / DFS
//2017/08/02

#include <cstdio>
#include <cstring>

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int n,map[102][102],visit[101][101],cnt;

void dfs(int y, int x,int co) {

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (map[ty][tx] == co && !visit[ty][tx]) dfs(ty, tx, co);
	}
}

int main() {
	scanf("%d", &n);

	char tmp[101];
	for (int y = 1; y <= n; y++) {
		scanf("%s", tmp);
		for (int x = 1; x <= n; x++) {
			if (tmp[x - 1] == 'R') map[y][x] = 1;
			else if (tmp[x - 1] == 'G') map[y][x] = 2;
			else map[y][x] = 3;
		}
	}

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (!visit[y][x]) {
				dfs(y, x, map[y][x]);
				cnt++;
			}
		}
	}
	printf("%d ", cnt);
	memset(visit, 0, sizeof(visit));
	cnt = 0;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			if (map[y][x] == 2) map[y][x] = 1;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (!visit[y][x]) {
				dfs(y, x, map[y][x]);
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}