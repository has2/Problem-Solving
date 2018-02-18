//BOJ
//ID : 2665 // dijkstra
//2017/10/19

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 },INF=300000;
int dist[50][50], map[50][50];
int n;
struct P { int y, x,c; };
bool operator<(P a, P b) {
	return a.c > b.c;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char ch;
			scanf(" %c", &ch);
			map[i][j] = ch - '0';
		}
	priority_queue<P> pq;
	pq.push({ 0,0,0 });
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, INF);
	dist[0][0] = 0;

	while (!pq.empty()) {
		int hy = pq.top().y;
		int hx = pq.top().x;
		int hc = pq.top().c;
		pq.pop();
		if (hc > dist[hy][hx]) continue;

		for (int i = 0; i < 4; i++) {
			int ty = hy + dy[i], tx = hx + dx[i];
			if (ty < 0 || tx < 0 || ty >= n || tx >= n) continue;
			if (hc + 1-map[ty][tx] < dist[ty][tx]) {

				dist[ty][tx] = hc + 1-map[ty][tx];
				pq.push({ ty,tx,dist[ty][tx] });
			}
		}
	}
	printf("%d", dist[n - 1][n - 1]);
}