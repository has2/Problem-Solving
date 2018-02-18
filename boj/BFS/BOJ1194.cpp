//BOJ
//ID : 1194 // bfs
//2017/10/18

#include <cstdio>
#include <queue>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m, sy, sx,ret;
bool visit[50][50][1 << 6];
char map[50][50];
struct P { int y, x, key; };

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '0') sy = i, sx = j;
		}

	queue<P> q;
	q.push({ sy,sx,0 });
	visit[sy][sx][0] = 1;
	while (!q.empty()) {

		int qsize = q.size();
		while (qsize--) {

			P here = q.front(); q.pop();
			int hy = here.y, hx = here.x, hk = here.key;
			if (map[hy][hx] == '1') {
				printf("%d", ret);
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (ty < 0 || tx < 0 || ty >= n || tx >= m || map[ty][tx] == '#') continue;

				if ('A' <= map[ty][tx] && map[ty][tx] <= 'F') {
					int tk = map[ty][tx] - 'A';
					if (((1 << tk)&hk) && !visit[ty][tx][hk]) {
						q.push({ ty,tx,hk });
						visit[ty][tx][hk] = 1;
					}
				}
				else if ('a' <= map[ty][tx] && map[ty][tx] <= 'f') {
					int tk = map[ty][tx] - 'a';
					if (!visit[ty][tx][hk |(1<<tk)]) {
						q.push({ ty,tx,hk|(1<<tk) });
						visit[ty][tx][hk |(1<<tk)] = 1;
					}
				}
				else if (!visit[ty][tx][hk]) {
					q.push({ ty,tx,hk });
					visit[ty][tx][hk] = 1;
				}
			}
		}
		ret++;
	}
	puts("-1");
}
