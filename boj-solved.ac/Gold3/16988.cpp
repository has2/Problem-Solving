#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int map[20][20],N, M;
bool visit[20][20],ok;

void dfs(int y, int x,set<pair<int,int>>& cands) {
	visit[y][x] = 1;
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == 1) continue;
		if (map[ny][nx] == 2) dfs(ny, nx, cands);
		else cands.insert({ ny,nx });
	}
}

int dfs2(int y, int x) {
	visit[y][x] = 1;
	int cnt = 1;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx] || map[ny][nx] == 1) continue;
		if (map[ny][nx] == 2) {
			int ret = dfs2(ny, nx);
			cnt += ret;
		}
		else ok = 0;
	}
	return cnt;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	set<pair<int, int>> cset;
	int group = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && map[i][j] == 2) {
				set<pair<int, int>> c;
				dfs(i, j, c);
				if (c.size() < 3) for (auto a : c) cset.insert(a);
			}
		}
	}
	vector<pair<int,int>> cv;
	for (auto c : cset) cv.push_back(c);
	int ans = 0;
	for (int p = 0; p < (int)cv.size(); p++) {
		for (int q = 0; q < (int)cv.size(); q++) {
			map[cv[q].first][cv[q].second] = map[cv[p].first][cv[p].second] = 1;
			int res = 0;
			memset(visit, 0, sizeof(visit));
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < M; x++) {
					if (!visit[y][x] && map[y][x] == 2) {
						ok = 1;
						int ret = dfs2(y, x);
						if (ok) res += ret;
					}
				}
			}
			ans = max(ans, res);
			map[cv[q].first][cv[q].second] = map[cv[p].first][cv[p].second] = 0;
		}
	}
	printf("%d", ans);
}