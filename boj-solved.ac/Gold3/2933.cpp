#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct P {
	int y, x;
};
const int mxN = 101, INF = 987654321;
int R, C, a[mxN], t;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
char map[mxN][mxN];
int group[mxN][mxN];
vector<P> groups[10001];
bool range(int y, int x) {
	return y < 1 || x < 1 || y > R || x > C;
}
bool cmp(P& a, P& b) {
	if (a.x < b.x) return 1;
	else if (a.x == b.x) return a.y < b.y;
	return 0;
}
void dfs(int y, int x, int g) {

	group[y][x] = g;
	groups[g].push_back({ y,x });

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (range(ny, nx) || map[ny][nx] == '.' || group[ny][nx]) continue;
		dfs(ny, nx, g);
	}
}
int getDist(int y, int x) {
	int ret = 0;
	int ny = y - 1;
	while (1) {
		if (range(ny, x) || map[ny][x] == 'x') break;
		ny--;
		ret++;
	}
	return ret;
}

int main() {

	scanf("%d%d", &R, &C);
	for (int i = R; i >= 1; i--)
		for (int j = 1; j <= C; j++) scanf(" %c", &map[i][j]);

	scanf("%d", &t);
	int tt = 0;
	while (tt<t) {
		int y;
		scanf("%d", &y);
		int x, d;
		if (tt % 2 == 0) {
			x = 1;
			d = 1;
		}
		else {
			x = C;
			d = -1;
		}
		tt++;
		bool ok = 0;
		while (1) {
			if (range(y, x)) break;
			if (map[y][x] == 'x') {
				ok = 1;
				break;
			}
			x += d;
		}
		if (!ok) continue;

		map[y][x] = '.';
		memset(group, 0, sizeof(group));
		for (int i = 0; i <= R*C; i++) groups[i].clear();

		int g = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] == 'x' && !group[i][j]) {
					g++;
					dfs(i, j, g);
				}
			}
		}

		for (int i = 1; i <= g; i++) {
			sort(groups[i].begin(), groups[i].end(), cmp);
			int prev = -1;
			int minDist = INF;
			for (auto k : groups[i]) {
				if (prev != k.x) {
					minDist = min(minDist, getDist(k.y, k.x));
					prev = k.x;
				}
			}
			if (minDist == 0) continue;

			for (auto k : groups[i]) {
				map[k.y - minDist][k.x] = 'x';
				map[k.y][k.x] = '.';
			}
		}
	
	}

	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			printf("%c", map[i][j]);
		}
		puts("");
	}
}