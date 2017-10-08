//SW Expert
//ID : 1949 // backtracking
//2017/10/08

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n,k,map[8][8],maxlen;
bool visit[8][8];
void sol(int y, int x,int rm,int len) {

	maxlen = max(maxlen, len);

	for (int i = 0; i < 4; i++) {
			int ty = y + dy[i], tx = x + dx[i];
			if (ty < 0 || tx < 0 || ty >= n || tx >= n || visit[ty][tx]) continue;
			if (map[ty][tx] < map[y][x]) {

				visit[ty][tx] = 1;
				sol(ty, tx, rm, len + 1);
				visit[ty][tx] = 0;
			}else if (rm == 1 && map[ty][tx] - k < map[y][x]) {

				visit[ty][tx] = 1;
				int tmp = map[ty][tx];
				map[ty][tx] = map[y][x] - 1;
				sol(ty, tx, 0, len + 1);
				map[ty][tx] = tmp;
				visit[ty][tx] = 0;
			}
	}
}

int main() {

	int tc;
	scanf("%d", &tc);
	for (int tcn = 1; tcn <= tc; tcn++) {

		int maxv = 0;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				maxv = max(map[i][j], maxv);
			}
		
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(map[i][j] != maxv) continue;
				maxlen = 0;
				visit[i][j] = 1;
				sol(i, j, 1, 1);
				visit[i][j] = 0;
	            res = max(maxlen, res);
			}
		}
		
		printf("#%d %d\n",tcn,res);
	}
}