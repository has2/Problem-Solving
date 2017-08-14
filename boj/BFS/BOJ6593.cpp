//BOJ
//ID : 6593 / BFS
//2017/08/12

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Plane {
	int x, y, z;
	Plane(int z, int y, int x) :z(z), y(y), x(x){}
};

const int dz[] = { 0,0,0,0,1,-1 };
const int dy[] = { 1,-1,0,0,0,0 };
const int dx[] = { 0,0,1,-1,0,0 };
int L, R, C, map[32][32][32], cost[31][31][31];
int sx,sy,sz,ex,ey,ez;

int main() {
	
	while (1) {

		memset(map, 0, sizeof(map));
		memset(cost, -1, sizeof(cost));

		scanf("%d%d%d", &L, &R, &C);
		if (!L&& !R && !C) break;

		for (int z = 1; z <= L; z++)
			for (int y = 1; y <= R; y++)
				for (int x = 1; x <= C; x++) {
					char a;
					scanf(" %c", &a);
					if (a == 'S') {
						sz = z; sy = y; sx = x;
					}
					else if (a == 'E') {
						ez = z; ey = y; ex = x;
						map[z][y][x] = 1;
					}
					else if (a == '.')
						map[z][y][x] = 1;
				}

		queue<Plane> q;
		q.push(Plane(sz, sy, sx));
		cost[sz][sy][sx] = 0;

		bool ok = false;
		while (!q.empty()) {

			Plane here = q.front(); q.pop();
			int z = here.z, y = here.y, x = here.x;

			if (z == ez && y == ey && x == ex) {
				ok = true;
				break;
			}

			for (int i = 0; i < 6; i++) {
				int tz = z + dz[i], ty = y + dy[i], tx = x + dx[i];
				if (map[tz][ty][tx] && cost[tz][ty][tx] == -1) {
					cost[tz][ty][tx] = cost[z][y][x] + 1;
					q.push(Plane(tz, ty, tx));
				}
			}
		}

		if (ok) printf("Escaped in %d minute(s).\n", cost[ez][ey][ex]);
		else puts("Trapped!");
	}
}

