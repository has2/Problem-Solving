//BOJ
//ID : 2468 // bfs
//2017/09/21

#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, map[100][100], ret, msafe,cnt;
bool visit[100][100];

void dfs(int y, int x, int safe) {

	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= n || map[ty][tx] <= safe || visit[ty][tx]) continue;
		dfs(ty, tx, safe);
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			msafe = max(msafe, map[i][j]);
		}

	for (int sf = 0; sf <= msafe; sf++) {
		int total = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (!visit[y][x] && map[y][x] > sf) {
					dfs(y, x, sf);
					total++;
				}
			}
		}
		ret = max(ret, total);
		memset(visit, 0, sizeof(visit));
	}
	printf("%d", ret);
}