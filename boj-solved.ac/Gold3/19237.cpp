#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct shark {
	int num, r, dir;
};
int n, m, K;
int dy[5] = { -1,1,0,0 };
int dx[5] = { 0,0,-1,1 };
int rule[401][4][4];

int getP(int s, int d, int i) {
	int prio;
	for (int k = 0; k < 4; k++) {
		if (rule[s][d][k] == i) {
			prio = k;
			break;
		}
	}
	return prio;
}
int move(int y, int x, vector<vector<vector<shark>>>& map) {

	vector<pair<int,int>> nosmell;
	vector<pair<int, int>> mysmell;
	int s = map[y][x].back().num;

	int d = map[y][x].back().dir;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (map[ny][nx].empty()) nosmell.push_back({ getP(s,d,i) ,i });
		else if(map[ny][nx].back().num == s) mysmell.push_back({ getP(s,d,i) ,i });
	}
	if (!nosmell.empty()) {
		auto ret = min_element(nosmell.begin(), nosmell.end());
		return ret->second;
	}
	auto ret = min_element(mysmell.begin(), mysmell.end());
	return ret->second;
}

int main() {
	scanf("%d%d%d", &n, &m, &K);
	int cnt = m;
	vector<vector<vector<shark>>> cur(n, vector<vector<shark>>(n));

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			int v;
			scanf("%d", &v);
			if (v > 0) cur[i][j].push_back({ v,K,0});
		}

	for (int i = 1; i <= m; i++) {
		int d;
		scanf("%d", &d);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!cur[j][k].empty() && cur[j][k].back().num == i) cur[j][k].back().dir = d-1;	
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				scanf("%d", &rule[i][j][k]);
				rule[i][j][k]--;
			}
		}
	}
	int time = 0;
	while (time<=1000 && cnt>1) {
		time++;
		vector<vector<vector<shark>>> next(n, vector<vector<shark>>(n));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cur[i][j].empty()) continue;

				int sn = cur[i][j].back().num;
				int sk = cur[i][j].back().r;
				int sd = cur[i][j].back().dir;
				if (sd == -1) {
					if (--sk != 0) {
						next[i][j].push_back({ sn,sk,sd });
					}
				}
				else {
					int nd = move(i, j, cur);
					int ny = i+dy[nd];
					int nx = j+dx[nd];
					if (K > 1) next[i][j].push_back({ sn,K - 1,-1 });
					next[ny][nx].push_back({ sn,K,nd });
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!next[i][j].empty()) {
					int idx = -1;
					int v = 500;
					int sharkcnt = 0;
					for (int k = 0; k < next[i][j].size(); k++) {
						if (next[i][j][k].dir != -1){
							sharkcnt++;
							if (next[i][j][k].num < v) {
								idx = k;
								v = next[i][j][k].num;
							}
						}
					}
					shark tmp = idx == -1 ? next[i][j][0] : next[i][j][idx];
					next[i][j].clear();
					next[i][j].push_back(tmp);
					if (sharkcnt > 0) cnt -= (sharkcnt - 1);
				}
			}
		}
		cur = next;
	}
	printf("%d\n", time > 1000 ? -1 : time);
}