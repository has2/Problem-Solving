//BOJ
//ID : 3184 // dfs
//2017/10/03

#include <cstdio>
int n, m, o, v, co, cv,ty,tx,dy[4] = { 1,-1,0,0 },dx[4] = { 0,0,1,-1 };
char a[252][252];
void dfs(int y, int x) {
	if (a[y][x] == 'o') co++;
	if (a[y][x] == 'v') cv++;
	a[y][x] = '#';
	for (int k = 0; k < 4; k++) {
		ty = y + dy[k], tx = x + dx[k];
		if (ty < 0 || tx < 0 || ty > n+1 || tx > m+1 || a[ty][tx] == '#') continue;
		dfs(ty, tx);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) scanf(" %c", &a[i][j]);
	dfs(0, 0);
	for (i = 2; i < n; i++) {
		for (j = 2; j < m; j++) {
			if (a[i][j] != '#') {
				co = cv = 0;
				dfs(i, j);
				if (co > cv) o += co;
				else v += cv;
			}
		}
	}
	printf("%d %d", o, v);
}