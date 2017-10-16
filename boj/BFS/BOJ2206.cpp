//BOJ
//ID : 2206 // BFS
//2017/10/16

#include <cstdio>
#include <queue>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m;
char map[1000][1000];
bool visit[2][1000][1000];

struct P {
	int u,y, x;
};

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &map[i][j]);
			map[i][j] -= '0';
		}

	queue<P> q;
	q.push({ 1, 0, 0 });
	visit[1][0][0] = 1;

	int dep = 0;
	while (!q.empty()) {

		int qsize = q.size();
		dep++;
		while (qsize--) {

			int hy = q.front().y;
			int hx = q.front().x;
			int hu = q.front().u; q.pop();
			if (hy == n - 1 && hx == m - 1) {
				printf("%d", dep);
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (ty < 0 || tx < 0 || ty >= n || tx >= m) continue;
				if (!map[ty][tx] && !visit[hu][ty][tx]) {
					q.push({ hu, ty, tx });
					visit[hu][ty][tx] = 1;
				}
				else if (hu && !visit[0][ty][tx]) {
					q.push({0, ty, tx});
					visit[0][ty][tx] = 1;
				}
			}
		}
	}
	puts("-1");
}