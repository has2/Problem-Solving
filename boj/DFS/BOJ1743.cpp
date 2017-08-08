//BOJ
//ID : 1743 / DFS
//2017/08/02

#include <cstdio>
#include <algorithm>

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
int n,m,cnt,map[102][102],visit[102][102],k;

void dfs(int y, int x) {

	visit[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (map[ty][tx] && !visit[ty][tx]) dfs(ty, tx);
	}
}

int main() {
	
	scanf("%d%d%d", &n, &m, &k);
	while (k--) {
		int y, x;
		scanf("%d%d", &y, &x);
		map[y][x] = 1;
	}

	int ans = -1;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (!visit[y][x] && map[y][x]) {
				cnt = 0;
				dfs(y, x);
				ans = std::max(cnt, ans);
			}
		}
	}
	printf("%d", ans);
}