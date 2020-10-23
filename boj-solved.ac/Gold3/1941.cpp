#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool a[25],check[25][25],visit[25][25];
char m[25][25];
int b = 7,t=25,ret;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int dfs(int y, int x) {
	visit[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || visit[ny][nx]) continue;
		if (check[ny][nx]) ret += dfs(ny, nx);
	}
	return ret;
}
int main() {
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) scanf(" %c", &m[i][j]);
	
	for (int i = t-b; i < t; i++) a[i] = 1;
	
	do {
		int cnt = 0,y,x;
		memset(visit, 0, sizeof(visit));
		memset(check, 0, sizeof(check));
		for (int i = 0; i < t; i++) {
			if (a[i]) {
				if (m[i / 5][i % 5] == 'S') cnt++;
				check[i / 5][i % 5] = 1;
				y = i / 5, x = i % 5;
			}
		}
		if (cnt > 3 && dfs(y, x)==7) ret++;
	} while (next_permutation(a, a + t));
	printf("%d", ret);
}