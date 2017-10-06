//BOJ
//ID : 2589 // bfs
//2017/10/06

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m,ret;
char map[52][52];
struct P {
	int y, x;
	P(int y,int x):y(y),x(x){}
};

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &map[i][j]);
	
	queue<P> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 'L') {

				bool visit[52][52] = { 0 };
				q.push(P(i, j));
				visit[i][j] = 1;
				int maxd = 0;
				while (!q.empty()) {

					int qsize = q.size();
					while (qsize--) {

						int hy = q.front().y;
						int hx = q.front().x; q.pop();

						for (int i = 0; i < 4; i++) {
							int ty = hy + dy[i], tx = hx + dx[i];
							if (!map[ty][tx] || map[ty][tx] == 'W' || visit[ty][tx]) continue;
							q.push(P(ty, tx));
							visit[ty][tx] = 1;
						}
					}
					maxd++;
				}
				ret = max(ret, maxd-1);
			}
		}
	}
	printf("%d", ret);
}