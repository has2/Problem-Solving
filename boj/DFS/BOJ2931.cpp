//BOJ
//ID : 2931 // DFS
//2017/10/16

#include <cstdio>

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool pipe[8][4] = { {0,0,0,0},{1,1,0,0},{0,0,1,1},{1,1,1,1},{1,0,1,0},{0,1,1,0},{0,1,0,1},{1,0,0,1} };
int n, m, map[25][25], zy, zx, my, mx,ry,rx;
bool visit[25][25],rd[4];

int oppo(int d) {
	return d < 2 ? 1 - d : 5 - d;
}

void dfs(int y, int x) {

	visit[y][x] = 1;

	int pnum = map[y][x];

	for (int i = 0; i < 4; i++) {
		if (!pipe[pnum][i]) continue;
		int ty = y + dy[i], tx = x + dx[i];
		if (visit[ty][tx]) continue;
		if (map[ty][tx]) {
			visit[ty][tx]=1;
			dfs(ty, tx);
		}
		else {
			ry = ty; rx = tx;
			rd[oppo(i)] = 1;
		}
	}

}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			scanf(" %c", &c);
			if (c == '|') map[i][j] = 1;
			else if (c == '-') map[i][j] = 2;
			else if (c == '+') map[i][j] = 3;
			else if (c == '1') map[i][j] = 4;
			else if (c == '2') map[i][j] = 5;
			else if (c == '3') map[i][j] = 6;
			else if (c == '4') map[i][j] = 7;
			else if (c == 'M') my = i, mx = j;
			else if (c == 'Z') zy = i, zx = j;
		}
	}
	visit[my][mx] = 1;
	visit[zy][zx] = 1;
	for (int i = 0; i < 4; i++) {
		int ty = my + dy[i], tx = mx + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m || map[ty][tx] != 0) continue;
		dfs(ty, tx);
		ty = zy + dy[i], tx = zx + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m || map[ty][tx] != 0) continue;
		dfs(ty, tx);
	}

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (map[i][j] && !visit[i][j]) dfs(i, j);

	int rp;
	for (int i = 1; i < 8; i++) {
		bool ok = 0;
		for (int j = 0; j < 4; j++) {
			if (pipe[i][j] != rd[j]) break;
			if (j == 3) {
				ok = 1;
				rp = i;
				break;
			}
		}
		if (ok) break;
	}
	char ch;
	if (rp == 1) ch = '|';
	else if (rp == 2) ch = '-';
	else if (rp == 3) ch = '+';
	else if (rp == 4) ch = '1';
	else if (rp == 5) ch = '2';
	else if (rp == 6) ch = '3';
	else if (rp == 7) ch = '4';

	printf("%d %d %c\n", ry+1, rx+1, ch);
}