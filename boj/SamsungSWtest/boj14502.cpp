//BOJ
//ID : 14502 / DFS,Bruteforce
//2017/09/05

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 1000;
int n, m, map[9][9], ret = INF, cnt, sum;
bool visit[9][9];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> cand, candvi;

void dfs(int y, int x) {

	if (map[y][x] != 2)
		cnt++;
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 1 || tx < 1 || ty > n || tx > m) continue;
		if (map[ty][tx] != 1 && !visit[ty][tx])
			dfs(ty, tx);
	}

}

int main() {
	scanf("%d%d", &n, &m);
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 0) {
				cand.push_back(make_pair(y, x));
				sum++;
			}
			else if (map[y][x] == 2)
				candvi.push_back(make_pair(y, x));

		}
	}

	for (int i = 0; i < cand.size(); i++) {
		for (int j = 0; j < cand.size(); j++) {
			for (int k = 0; k < cand.size(); k++) {
				if (i == j || j == k || i == k) continue;

				map[cand[i].first][cand[i].second] = 1;
				map[cand[j].first][cand[j].second] = 1;
				map[cand[k].first][cand[k].second] = 1;

				memset(visit, 0, sizeof(visit));
				int cur = 0;

				for (auto pt : candvi) {
					int y = pt.first;
					int x = pt.second;

					if (!visit[y][x]) {
						dfs(y, x);
						cur += cnt;
						cnt = 0;
					}
				}

				ret = min(cur, ret);

				map[cand[i].first][cand[i].second] = 0;
				map[cand[j].first][cand[j].second] = 0;
				map[cand[k].first][cand[k].second] = 0;
			}
		}
	}
	printf("%d", sum - 3 - ret);
}




