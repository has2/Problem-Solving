#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int dz[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 0,0,0,0,1,-1 };
vector<int> seq = { 0,1,2,3,4 };
struct P {
	int z, y, x;
};
vector<vector<int>> shape[5][4];
int pick[5],INF=987654321,ans = INF;;
bool visit[5][5][5];
vector<vector<int>> rotate(vector<vector<int>>& m) {
	vector<vector<int>> ret(5, vector<int>(5));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ret[i][j] = m[4 - j][i];
		}
	}
	return ret;
}
int bfs() {
	
	vector<vector<int>> cmap[5];
	for (int i = 0; i < 5; i++) cmap[i] = shape[seq[i]][pick[i]];

	memset(visit, 0, sizeof(visit));
	queue<P> q;
	if (!cmap[0][0][0] || !cmap[4][4][4]) return INF;
	q.push({ 0,0,0 });
	visit[0][0][0] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int qsz = q.size();
		if (cnt > INF) return INF;
		while (qsz--) {
			P f = q.front(); q.pop();
			if (f.z == 4 && f.y == 4 && f.x == 4) {
				return cnt;
			}
			for (int i = 0; i < 6; i++) {
				int nz = f.z + dz[i];
				int ny = f.y + dy[i];
				int nx = f.x + dx[i];
				if (nz < 0 || ny < 0 || nx < 0 || nz >= 5 || ny >= 5 || nx >= 5 || visit[nz][ny][nx] || !cmap[nz][ny][nx]) continue;
				q.push({ nz,ny,nx });
				visit[nz][ny][nx] = 1;
			}
		}
		cnt++;
	}
	return INF;
}
int choose(int cur) {
	if (cur == 5) return bfs();
	int ret = INF;
	for (int i = 0; i < 4; i++) {
		pick[cur] = i;
		ret = min(ret,choose(cur + 1));
	}
	return ret;
}
int main() {

	vector<vector<vector<int>>> map(5, vector<vector<int>>(5, vector<int>(5)));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) scanf("%d", &map[i][j][k]);
		}
		shape[i][0] = map[i];
		for (int j = 1; j < 4; j++) shape[i][j] = rotate(shape[i][j-1]);
	}
	do {
		ans = min(ans,choose(0));
		if (ans == 12) {
			puts("12");
			return 0;
		}
	} while (next_permutation(seq.begin(), seq.end()));
	printf("%d\n", ans==INF ? -1 : ans);
}