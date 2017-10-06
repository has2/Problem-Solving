//BOJ
//ID : 5022 // dfs,bfs
//2017/10/04

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct P {
	int y, x;
	P(){}
	P(int y,int x):y(y),x(x){}
	bool operator==(P& a) const {
		return (a.y == y && a.x == x);
	}
	P operator+(const P& a) {
		P temp(y + a.y, x + a.x);
		return temp;
	}
};

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m,ret=20000,th;
P p[4];
bool map[101][101];

int bfs() {

	queue<P> q;
	bool visit[101][101] = { 0, };

	q.push(p[2]);
	visit[p[2].y][p[2].x] = 1;

	int bc = 0;

	while (!q.empty()) {

		int qsize = q.size();
		while (qsize--) {

			P here = q.front(); q.pop();

			if (here == p[3]) {
				return bc;
			}
			for (int i = 0; i < 4; i++) {
				int ty = here.y + dy[i], tx = here.x + dx[i];
				if (ty < 0 || tx < 0 || ty >= n || tx >= m
					|| visit[ty][tx] || map[ty][tx]) continue;
				q.push(P(ty, tx));
				visit[ty][tx] = 1;
			}
		}
		bc++;
	}
	return -1;
}


void dfs(P h, int c) {

	if (c > th) return;
	map[h.y][h.x] = 1;
	
	if (h == p[1]) {
		int ok = bfs();
		if (ok != -1) ret = min(ret, ok + c);
	}

	for (int i = 0; i < 4; i++) {
		int ty = h.y + dy[i], tx = h.x + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m
			|| h == p[2] || h == p[3] || map[ty][tx]) continue;

		dfs(P(ty,tx), c + 1);
	}
	map[h.y][h.x] = 0;
}

int main() {

	scanf("%d%d", &n, &m);
	n++, m++;
	for (int i = 0; i < 4; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		p[i] = P(b, a);
	}
	if (n > m) th = m + 2 * n;
	else th = 2 * m + n;
	dfs(p[0], 0);
	
	printf("%d", ret);
}