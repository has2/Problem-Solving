//BOJ
//ID : 14503 / Simulation
//2017/09/05

#include <cstdio>
int n, m, map[51][51],dir,cy,cx,ret,ck;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int left() {
	return dir % 2 == 0 ? 3 - dir : dir - 1;
}
int main() {

	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &cy, &cx, &dir);
	cy++, cx++;
	cy = n - cy+1;
	for (int y = n; y >= 1; y--) {
		for (int x = 1; x <= m; x++) {
				scanf("%d", &map[y][x]);
		}
	}

	while (1) {
		if (map[cy][cx] == 0) {
			map[cy][cx] = 2;
			ret++;
		}

		ck = 0;
		for (int i = 0; i < 4; i++)
			if (map[cy + dy[i]][cx + dx[i]]) ck++;

		if (ck==4) {
			int back = (dir + 2) % 4;
			if (map[cy + dy[back]][cx + dx[back]] == 1) break;
			else {
				cy +=dy[back];
				cx +=dx[back];
			}
		}
		else {
			int L = left();
			if (map[cy+dy[L]][cx+dx[L]] == 0) {
				cy += dy[L];
				cx += dx[L];	
			}
			dir = L;
		}
	}
	printf("%d", ret);
}



