//BOJ
//ID : 14502 // dfs
//2017/10/18

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m, map[8][8],total;
bool iszero[64],visit[8][8];
void dfs(int y, int x) {

	visit[y][x] = 1;
	if (map[y][x] == 0) total--;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m || visit[ty][tx] || map[ty][tx] == 1) continue;
		
		dfs(ty, tx);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				iszero[i*m + j] = 1;
				total++;
			}
		}
	int tzero = total, msafe = 0;
	for(int i=0;i<n*m-2;i++)
		for(int j=i+1;j<n*m-1;j++)
			for (int k = j + 1; k < n*m; k++) {
				if (!iszero[i] || !iszero[j] || !iszero[k]) continue;

				map[i / m][i%m] = map[j / m][j%m] = map[k / m][k%m] = 1;
				memset(visit, 0, sizeof(visit));
				total = tzero-3;
				for (int y = 0; y < n; y++) {
					for (int x = 0; x < m; x++) {
						if (visit[y][x] || map[y][x] != 2) continue;
						dfs(y, x);
					}
				}
				msafe = max(msafe, total);
				map[i / m][i%m] = map[j / m][j%m] = map[k / m][k%m] = 0;
			}
	printf("%d", msafe);
}

