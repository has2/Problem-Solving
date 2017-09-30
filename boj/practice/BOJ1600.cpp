//BOJ
//ID : 2468 // bfs
//2017/09/21

#include <cstdio>
#include <queue>
using namespace std;

int kny[8] = { -2,-2,-1,-1,2,2,1,1 };
int knx[8] = { 1,-1,2,-2,1,-1,2,-2 };
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool map[200][200];
bool visit[200][200][31];
int k, w, h, ret;

struct P {
	int y, x, rm;
	P(int y, int x, int rm) :y(y), x(x), rm(rm) {}
};
int main() {
	scanf("%d%d%d", &k, &w, &h);

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf("%d", &map[i][j]);

	queue<P> q;
	q.push(P(0, 0, k));
	visit[0][0][k] = 1;

	while (!q.empty()) {

		int qsize = q.size();
		ret++;
		while (qsize--) {

			P here = q.front(); q.pop();
			int hy = here.y, hx = here.x, hrm = here.rm;

			if (hy == h - 1 && hx == w - 1) {
				printf("%d", ret - 1);
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (ty < 0 || tx < 0 || ty >= h || tx >= w || map[ty][tx] || visit[ty][tx][hrm]) continue;

				q.push(P(ty, tx, hrm));
				visit[ty][tx][hrm] = 1;
			}

			if (hrm > 0) {
				for (int i = 0; i < 8; i++) {

					int ty = hy + kny[i], tx = hx + knx[i];
					if (ty < 0 || tx < 0 || ty >= h || tx >= w || map[ty][tx] || visit[ty][tx][hrm - 1]) continue;

					q.push(P(ty, tx, hrm - 1));
					visit[ty][tx][hrm - 1] = 1;
				}
			}
		}
	}
	printf("-1");
}