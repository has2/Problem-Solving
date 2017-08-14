//BOJ
//ID : 1261 / Dijkstra
//2017/08/13

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;
const int dy[] = { 1,-1,0,0 };
const int dx[] = { 0,0,1,-1 };
struct P {
	int y,x,c;
	P(int y,int x,int c):y(y),x(x),c(c){}
};

bool operator<(const P& a, const P& b) {
	return a.c < b.c;
}

int n, m, map[101][101], dist[101][101];

int main() {
	scanf("%d%d", &m, &n);
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			char t;
			scanf(" %c", &t);
			map[y][x] = t - '0';
		}
	}

	for (int y = 1; y <= n; y++)
		fill(dist[y] + 1, dist[y] + 1 + m, INF);
	priority_queue<P> pq;
	pq.push(P(1, 1, 0));
	dist[1][1] = 0;


	while (!pq.empty()) {

		P here = pq.top(); pq.pop();
		int hy = here.y, hx = here.x, hc = -here.c;

		if (hc > dist[hy][hx]) continue;

		for (int i = 0; i < 4; i++) {
			int ty = hy + dy[i], tx = hx + dx[i];
			if (ty < 1 || tx < 1 || tx > m || ty > n) continue;
			int nD = hc + map[ty][tx];

			if (nD < dist[ty][tx]) {
				dist[ty][tx] = nD;
				pq.push(P(ty, tx, -nD));
			}
		}
	}
	printf("%d", dist[n][m]);
}

