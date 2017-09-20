//BOJ
//ID : 5427 // bfs
//2017/09/18
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int w, h, ret;
char map[1002][1002];

int main() {
	
	int c;
	scanf("%d", &c);

	while (c--) {
		queue<pair<int, int>> q;
		queue<pair<int, int>> fq;
		scanf("%d %d", &w, &h);

		bool ok = false;
		ret = 0;
		memset(map, 0, sizeof(map));

		for (int i = 1; i <= h; i++) {
			getchar();
			for (int j = 1; j <= w; j++) {
				map[i][j] = getchar();
				if (map[i][j] == '@') {
					map[i][j] = '#';
					q.push(make_pair(i, j));
				}
				if (map[i][j] == '*') {
					fq.push(make_pair(i, j));
					map[i][j] = '#';
				};
			}
		}

		while (1) {

			int fsize = fq.size();
			int qsize = q.size();

			if (qsize == 0) break;

			while (fsize--) {
				int hy = fq.front().first;
				int hx = fq.front().second;
				fq.pop();

				for (int i = 0; i < 4; i++) {
					int ty = hy + dy[i], tx = hx + dx[i];
					if (map[ty][tx] == '.') {
						fq.push(make_pair(ty, tx));
						map[ty][tx] = '*';
					}
				}
			}
			ret++;
			while (qsize--) {
				int hy = q.front().first;
				int hx = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {

					int ty = hy + dy[i], tx = hx + dx[i];

					if (map[ty][tx] == 0) {
						ok = true;
						break;
					}
					if (map[ty][tx] == '.') {
						q.push(make_pair(ty, tx));
						map[ty][tx] = '#';
					}
				}
			}
			if (ok) break;
		}
		if (ok) printf("%d\n", ret);
		else puts("IMPOSSIBLE");
	}
}