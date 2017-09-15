//BOJ
//ID : 14500 / DFS
//2017/09/04

#include <cstdio>

int n, m,ret;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int map[501][501];
bool visit[501][501];
void search(int y, int x,int dep,int val) {
	
	if (dep == 4) {
		if (val > ret) ret = val;
		return;
	}

	val = val + map[y][x];
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (!visit[ty][tx] && ty <= n && ty > 0 && tx <= m && tx > 0) {
			visit[ty][tx] = 1;
			search(ty, tx, dep + 1, val);
			visit[ty][tx] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) 
			scanf("%d", &map[i][j]);
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			visit[i][j] = 1;
			search(i, j, 0, 0);
			visit[i][j] = 0;

			for (int k = 0; k < 4; k++) {
				int cn = 0;
				int b = map[i][j];
				for (int p = 0; p < 4; p++) {
					int ty = i + dy[p], tx = j + dx[p];
					if (k != p && tx >= 1 && ty >= 1 && tx <= m && ty <= n) {
						cn++;
						b += map[ty][tx];
					}
					if (cn == 3 && b > ret) ret = b;
				}
			}
		}

	printf("%d\n", ret);
}




