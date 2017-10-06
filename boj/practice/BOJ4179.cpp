//BOJ
//ID : 4179 // bfs
//2017/10/04

#include <cstdio>
#include <queue>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m, ret;
char map[1002][1002];
struct P {
	int y, x;
	P(int y, int x) :y(y), x(x) {}
};
queue<P> q, f;
int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char ch;
			scanf(" %c", &ch);
			if (ch == 'J') {
				q.push(P(i, j));
				map[i][j] = 'J';
			}
			else if (ch == 'F') {
				f.push(P(i, j));
				map[i][j] = 'F';
			}
			else map[i][j] = ch;
		}

	while (!q.empty()) {
		int fsize = f.size(), qsize = q.size();

		while (fsize--) {
			int hy = f.front().y;
			int hx = f.front().x;
			f.pop();
			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (map[ty][tx] == '.' || map[ty][tx] == 'J') {
					f.push(P(ty, tx));
					map[ty][tx] = 'F';
				}
			}
		}
		ret++;

		while (qsize--) {
			int hy = q.front().y;
			int hx = q.front().x;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (map[ty][tx] == '.') {
					q.push(P(ty, tx));
					map[ty][tx] = 'J';
				}
				else if (map[ty][tx] == 0) {
					printf("%d", ret);
					return 0;
				}
			}
		}
	}
	puts("IMPOSSIBLE");
}