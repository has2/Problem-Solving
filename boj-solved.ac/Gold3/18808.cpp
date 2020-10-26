#include <cstdio>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
int N, M,K,ans;
vvi sticker[100][4];
bool map[40][40];
vvi rotate(vvi& m) {
	vvi ret;
	int r = m[0].size();
	int c = m.size();
	for (int i = 0; i < r; i++) {
		vector<int> rows;
		for (int j = 0; j < c; j++) rows.push_back(m[c-1-j][i]);
		ret.push_back(rows);
	}
	return ret;
}
bool pos(int y, int x, vvi& st) {
	int r = st.size();
	int c = st[0].size();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int ny = y + i;
			int nx = x + j;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) return 0;
			if (st[i][j] && map[ny][nx]) return 0;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int ny = y + i;
			int nx = x + j;
			if (st[i][j]) {
				map[ny][nx] = st[i][j];
				ans++;
			}
		}
	}
	return 1;
}
void attach(int k) {
	auto sts = sticker[k];
	for (int d = 0; d < 4; d++) {
		vvi st = sts[d];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (pos(i, j, st)) return;
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		int r, c,v;
		scanf("%d%d", &r, &c);
		for (int j = 0; j < r; j++) {
			vector<int> rows;
			for (int l = 0; l < c; l++) {
				scanf("%d", &v);
				rows.push_back(v);
			}
			sticker[i][0].push_back(rows);
		}
		for (int j = 1; j < 4; j++) sticker[i][j] = rotate(sticker[i][j - 1]);
		attach(i);
	}
	printf("%d", ans);
}