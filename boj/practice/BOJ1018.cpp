//BOJ
//ID : 1018 // brute force
//2017/10/07

#include <cstdio>
#include <algorithm>
int n, m,ret=80;
char map[51][51], color[2] = { 'W','B' };

int check(int y, int x, int c) {

	int total = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char cur = map[y + i][x + j];
			if ((j+i)% 2 == 0 && cur != color[c] || (j+i) % 2 == 1 && cur == color[c]) total++;
		}
	}
	return total;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &map[i][j]);

	for (int i = 1; i <= n - 7; i++) {
		for (int j = 1; j <= m - 7; j++) {
			ret = std::min(ret, check(i, j, 0));
			ret = std::min(ret, check(i, j, 1));
		}
	}
	printf("%d", ret);
}