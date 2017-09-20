//BOJ
//ID : 1726 // bfs
//2017/09/19

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int m, n,map[102][102],visit[102][102][4],ey,ex,ed,ret;

struct P {
	int y, x, d;
	P(int y, int x, int d) :y(y), x(x), d(d){}
};
int rL(int d) {
	return (d < 2) ? d + 2 : 3 - d;
}
int rR(int d) {
	return (d < 2) ? 3 - d : d - 2;
}

int main() {

	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) 
			scanf("%d", &map[i][j]);

	queue<P> q;
	scanf("%d%d%d", &ey, &ex, &ed);
	visit[ey][ex][--ed] = 1;
	q.push(P(ey, ex, ed));
	scanf("%d%d%d", &ey, &ex, &ed);
	ed--;

	while (1) {
		ret++;
		int qsize = q.size();
		while (qsize--) {
			P here = q.front(); q.pop();
			int hy = here.y, hx = here.x, hd = here.d;

			if (hy == ey && hx == ex && hd == ed) {
				printf("%d", ret-1);
				return 0;
			}
			int a[2] = { rL(hd),rR(hd) };

			for (int nd : a) {
				if (!visit[hy][hx][nd]) {
					visit[hy][hx][nd] = 1;
					q.push(P(hy, hx, nd));
				}
			}

			for (int i = 1; i <4 ; i++) {
				bool ok = true;
				int ty, tx;
				for (int k = 1; k <= i; k++) {
					ty = hy + k*dy[hd], tx = hx + k*dx[hd];
					if (ty < 1 || tx < 1 || ty > m || tx > n || map[ty][tx]) {
						ok = false;
						break;
					}
				}
				if (ok && !visit[ty][tx][hd]) {
					visit[ty][tx][hd] = 1;
					q.push(P(ty, tx, hd));
				}
			}
		}
	}
}