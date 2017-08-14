//BOJ
//ID : 4485 / Dijkstra
//2017/08/13

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
int n, dist[125][125],map[125][125];

struct Point {
	int y, x, c;
	Point(int c,int y,int x):c(c),y(y),x(x){}
};
bool operator < (Point a, Point b) {
	return a.c < b.c;
}
void dijk(int y,int x) {

	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, INF);

	priority_queue<Point> pq;

	dist[y][x] = map[y][x];
	pq.push(Point(-dist[y][x], y, x));

	while (!pq.empty()) {

		Point p = pq.top(); pq.pop();
		int hy = p.y,hx = p.x,hc = -p.c;

		if (hc > dist[hy][hx]) continue;

		for (int i = 0; i < 4; i++) {
			int ty = hy + dy[i], tx = hx + dx[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;

			if (dist[ty][tx] > dist[hy][hx] + map[ty][tx]) {
				dist[ty][tx] = dist[hy][hx] + map[ty][tx];
				pq.push(Point(-dist[ty][tx], ty, tx));
			}
		}
	}
}

int main() {

	int c = 0;
	while (++c) {
		scanf("%d", &n);
		if (n == 0) return 0;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				scanf("%d", &map[y][x]);

		dijk(0, 0);
		printf("Problem %d: %d\n",c,dist[n - 1][n - 1]);
	}
}

