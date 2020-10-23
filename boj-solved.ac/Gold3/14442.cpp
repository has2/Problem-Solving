#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct P {
	int y, x, k;
};
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N, M, K;
char map[1001][1001];
int dist[1001][1001][11];

int main() {

	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf(" %c", &map[i][j]);

	queue<P> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {

		P p = q.front(); q.pop();
		if (p.y == N - 1 && p.x == M - 1) {
			printf("%d", dist[p.y][p.x][p.k]);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = p.y + dy[i];
			int nx = p.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == '0') {
				if (!dist[ny][nx][p.k]) {
					q.push({ ny, nx, p.k });
					dist[ny][nx][p.k] = dist[p.y][p.x][p.k]+1;
				}
			}
			else if(p.k < K){
				if (!dist[ny][nx][p.k+1]) {
					q.push({ ny, nx, p.k+1 });
					dist[ny][nx][p.k+1] = dist[p.y][p.x][p.k] + 1;
				}
			}
		}
	}

	puts("-1");
}