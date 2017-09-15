//BOJ
//ID : 2615 / Bruteforce
//2017/09/10

#include <cstdio>

int dy[4][7] = {
	{ 0,0,0,0,0,0,0 },
	{ 0,1,2,3,4,5,-1 },
	{ 0,1,2,3,4,5,-1 },
	{ 0,-1,-2,-3,-4,-5,1 }
};
int dx[4][7] = {
	{ 0,1,2,3,4,5,-1 },
	{ 0,0,0,0,0,0,0 },
	{ 0,1,2,3,4,5,-1 },
	{ 0,1,2,3,4,5,-1 }
};
int board[19][19];

int main() {
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			scanf("%d", &board[i][j]);

	for (int y = 0; y < 19; y++) {
		for (int x = 0; x < 19; x++) {

			int t = board[y][x];
			if (t == 0) continue;

			for (int i = 0; i < 4; i++) {
				bool ok = true;
				for (int j = 0; j < 7; j++) {
					int ty = y + dy[i][j], tx = x + dx[i][j];

					if ((j < 5) &&
						(ty < 0 || tx < 0 || tx > 18 || ty > 18 || t != board[ty][tx])) {
						ok = false;
						break;
					}

					if ((j >= 5) && (ty >= 0 && tx >= 0 && tx < 19 && ty < 19 && t == board[ty][tx])) {
						ok = false;
						break;
					}
				}
				if (ok) {
					printf("%d\n%d %d", t, y + 1, x + 1);
					return 0;
				}
			}
		}
	}
	puts("0");
}