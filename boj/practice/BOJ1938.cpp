//BOJ
//ID : 1938 // bfs
//2017/09/21

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int dy[2][3] = { { 0,1,-1 },{ 0,0,0 } };
int dx[2][3] = { { 0,0,0 },{ 0,1,-1 } };
int mvy[4] = { 0,0,1,-1 };
int mvx[4] = { 1,-1,0,0 };

int n, map[50][50], sd, sy, sx, ed, ey, ex, ret;
vector<pair<int, int>> s, e;
bool visit[50][50][2];

struct P {
	int y, x, d;
	P(int y, int x, int d) :y(y), x(x), d(d) {}
};

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++) {
			int ch = getchar();
			if (ch == 'B') s.push_back(make_pair(i, j));
			if (ch == 'E') e.push_back(make_pair(i, j));
			map[i][j] = ch - '0' == 1 ? 1 : 0;
		}
	}

	int ok = 1;
	for (int i = 0; i < 2; i++) {
		if (s[i].first != s[i + 1].first) {
			ok = 0;
			break;
		}
	}
	sd = ok; sy = s[1].first; sx = s[1].second;

	ok = 1;
	for (int i = 0; i < 2; i++) {
		if (e[i].first != e[i + 1].first) {
			ok = 0;
			break;
		}
	}
	ed = ok; ey = e[1].first; ex = e[1].second;

	queue<P> q;
	q.push(P(sy, sx, sd));
	visit[sy][sx][sd] = 1;

	while (!q.empty()) {

		int qsize = q.size();

		ret++;
		while (qsize--) {

			P here = q.front(); q.pop();
			int hy = here.y, hx = here.x, hd = here.d;

			if (hy == ey && hx == ex && hd == ed) {
				printf("%d", ret - 1);
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int ty = hy + mvy[i], tx = hx + mvx[i];

				if (!visit[ty][tx][hd]) {
					bool ok = true;
					for (int i = 0; i < 3; i++) {
						int ky = ty + dy[hd][i], kx = tx + dx[hd][i];

						if (ky < 0 || kx < 0 || ky >= n || kx >= n || map[ky][kx] == 1) {
							ok = false;
							break;
						}
					}

					if (ok) {
						q.push(P(ty, tx, hd));
						visit[ty][tx][hd] = 1;
					}
				}
			}

			if (!visit[hy][hx][1 - hd]) {
				bool ok = true;

				for (int i = hy - 1; i <= hy + 1; i++) {
					for (int j = hx - 1; j <= hx + 1; j++) {
						if (i < 0 || j < 0 || i >= n || j >= n || map[i][j] == 1) {
							ok = false;
							break;
						}
						if (!ok) break;
					}
				}

				if (ok) {
					q.push(P(hy, hx, 1 - hd));
					visit[hy][hx][1 - hd];
				}
			}
		}
	}
	printf("0");
}