//BOJ
//ID : 14499 / Simulation
//2017/09/05

#include <cstdio>
int n, m, cy, cx, k,dir;
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int dice[7],map[20][20];
int main() {
	scanf("%d%d%d%d%d", &n, &m, &cy, &cx, &k);
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			scanf("%d", &map[y][x]);

	while (k--) {
		scanf("%d", &dir);
		
		int ty = cy + dy[dir], tx = cx + dx[dir];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m) continue;
		cy = ty; cx = tx;

		int tmp;
		if (dir == 1) {
			tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
		}
		else if (dir == 2) {
			tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
		}
		else if (dir == 4) {
			tmp = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = tmp;
		}
		else {
			tmp = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = dice[1];
			dice[1] = tmp;
		}

		if (map[cy][cx] == 0) {
			map[cy][cx] = dice[6];
		}
		else {
			dice[6] = map[cy][cx];
			map[cy][cx] = 0;
		}
		printf("%d\n", dice[1]);
	}
}



