//BOJ
//ID : 4920 / 테트리스 블록 90도 회전인지, 좌우 대칭까지 되는지 확인
//2017/09/07

#include <cstdio>
#include <climits>
#include <algorithm>

int dy[13][4] = {
	{0,1,2,3 },
	{0,0,0,0 },
	{0,0,1,1},
	{0,0,1,1},
	{0,0,-1,1},
	{0,0,0,1},
	{0,0,-1,-2},
	{0,1,1,1},
	{0,0,1,2},
	{0,0,0,1},
	{0,0,-1,1},
	{0,1,1,1},
	{0,1,1,2}
};
int dx[13][4] = {
	{0,0,0,0},
	{0,1,2,3},
	{0,1,0,1},
	{0,1,1,2},
	{0,1,1,0},
	{0,1,2,2},
	{0,1,1,1},
	{0,0,1,2},
	{0,1,0,0},
	{0,1,2,1},
	{0,1,1,1},
	{0,-1,0,1},
	{0,0,1,0}
};
int n, map[101][101],it;

int main() {

	while (1) {
		scanf("%d", &n);
		if (!n) return 0;

		int ret = INT_MIN;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &map[i][j]);

		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {

				for (int k = 0; k < 13; k++) {

					bool ok = true;
					int b = 0;
					for (int i = 0; i < 4; i++) {
						int ty = y + dy[k][i], tx = x + dx[k][i];
						if (ty<1 || tx <1 || ty > n || tx > n) {
							ok = false;
							break;
						}
						b += map[ty][tx];
					}
					if (ok) ret = std::max(ret, b);
				}
			}
		}
		printf("%d. %d\n",++it,ret);
	}
}



