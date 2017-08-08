//BOJ
//ID : 2468 / DFS
//2017/08/02

#include <cstdio>
#include <cstring>
#include <algorithm>
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int n,map[102][102],visit[102][102],cnt;

void dfs(int y, int x, int th) {

	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (!visit[ty][tx] && map[ty][tx] > th) {
			dfs(ty, tx,th);
		}
	}
}

int main() {

	scanf("%d", &n);

	int maxth = -1;
	for (int y = 1; y <= n; y++) 
		for (int x = 1; x <= n; x++) {
			scanf("%d", &map[y][x]);
			maxth = std::max(maxth, map[y][x]);
		}
	
	int ret = -1;

	for (int th = 0; th <= maxth; th++) {
		int cnt = 0;
		for (int y=1; y <= n; y++) {
			for (int x=1; x <= n; x++) {
				if (!visit[y][x] && map[y][x] > th) {
					dfs(y, x, th);
					cnt++;
				}
			}
		}
		ret = std::max(cnt, ret);
		memset(visit, 0, sizeof(visit));
	}
	printf("%d", ret);
}