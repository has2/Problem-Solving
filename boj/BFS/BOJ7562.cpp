//BOJ
//ID : 2178 / BFS
//2017/08/12

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int dx[] = { 1,1,2,2,-1,-1,-2,-2};
const int dy[] = { -2,2,-1,1,-2,2,-1,1};

int sx, sy, ex, ey;
int L,map[300][300],cost[300][300];

int main() {
	
	int c;
	scanf("%d", &c);
	while (c--) {

		memset(cost, -1, sizeof(cost));
		memset(map, 0, sizeof(map));
		scanf("%d%d%d%d%d", &L, &sx, &sy, &ex, &ey);

		queue<pair<int, int>> q;
		q.push(make_pair(sy, sx));
		cost[sy][sx] = 0;

		while (!q.empty()) {

			pair<int, int> here = q.front(); q.pop();
			int y = here.first, x = here.second;

			if (y == ey && x == ex) break;

			for (int i = 0; i < 8; i++) {
				int ty = y + dy[i], tx = x + dx[i];
				if (ty < 0 || tx < 0 || ty >= L || tx >= L) continue;

				if (cost[ty][tx] == -1) {

					cost[ty][tx] = cost[y][x] + 1;
					q.push(make_pair(ty, tx));
				}
			}
		}
		printf("%d\n", cost[ey][ex]);
	}
}