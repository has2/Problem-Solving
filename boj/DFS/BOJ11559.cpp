//BOJ
//ID : 11559 // dfs,simulation
//2017/10/14

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n = 12, m = 6,total;
char map[12][6];
bool visit[12][6];

void dfs(int y, int x,char co,vector<pair<int,int>>& v) {

	v.push_back(make_pair(y, x));
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m || visit[ty][tx] || map[ty][tx] != co) continue;
		dfs(ty, tx, co,v);
	}
}



int main() {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf(" %c", &map[i][j]);

	bool ok = 1;
	while (ok) {
		ok = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] || map[i][j] == '.') continue;

				vector<pair<int, int>> v;
				dfs(i, j, map[i][j],v);
			
				if (v.size() < 4) continue;
				ok = 1;

				for (auto p : v) map[p.first][p.second] = '.';
			}
		}

		if (ok) {
			total++;

			for (int x = 0; x < m; x++) {
				for (int y = n-1; y >= 0; y--) {
					if (map[y][x] == '.') continue;

					int k;
					for (k = y + 1; k < n; k++) 
						if(map[k][x] != '.') break;

					if (k - y > 1) {
						map[k - 1][x] = map[y][x];
						map[y][x] = '.';
					}
				}
			}
		}
	}
	printf("%d\n", total);
}