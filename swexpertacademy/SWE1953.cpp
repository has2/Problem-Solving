//SW Expert
//ID : 1953 // brute force
//2017/10/08

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
const bool pipe[8][4] = { {0,0,0,0}, {1,1,1,1}, {1,1,0,0}, {0,0,1,1},{1,0,0,1},{0,1,0,1},
					{0,1,1,0},{1,0,1,0}
                  };
int map[50][50],n, m, sy, sx, L;
struct P {
	int y, x;
	P(int y,int x):y(y),x(x){}
};
int main() {

	int tc;
	scanf("%d", &tc);
	for (int tcs = 1; tcs <= tc; tcs++) {
		scanf("%d%d%d%d%d", &n, &m, &sy, &sx, &L);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &map[i][j]);

		if (L == 1) {
			printf("#%d %d\n", tcs, 1);
			continue;
		}
		queue<P> q;
		bool visit[50][50] = { 0, };
		q.push(P(sy, sx));
		visit[sy][sx] = 1;

		int total = 1;
		int time = 1;
		while (!q.empty()) {

			int qsize = q.size();

			while (qsize--) {

				int hy = q.front().y;
				int hx = q.front().x; q.pop();

				for (int i = 0; i < 4; i++) {
					if (!pipe[map[hy][hx]][i]) continue;
					int ty = hy + dy[i], tx = hx + dx[i];

					if (ty < 0 || tx < 0 || ty >= n || tx >= m || visit[ty][tx] || !map[ty][tx]) continue;

					int td = i < 2 ? 1 - i : 5 - i;

					if (!pipe[map[ty][tx]][td]) continue;

					q.push(P(ty, tx));
					visit[ty][tx] = 1;
					total++;
				}
			}
			time++;
			if (time == L) break;
		}
		printf("#%d %d\n",tcs,total);
	}
}