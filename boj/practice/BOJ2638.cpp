//BOJ
//ID : 2638 // dfs
//2017/09/22

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m, map[100][100],ret;
bool visit[100][100];

void dfs(int y, int x) {

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || tx < 0 || ty >= n || tx >= m) continue;
		if (map[ty][tx]) {
			map[ty][tx]++;
			continue;
		};

		if(!visit[ty][tx])
			dfs(ty, tx);
	}
}


int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			scanf("%d", &map[i][j]);

	while (1) {
		ret++;

		memset(visit, 0, sizeof(visit));

		dfs(0, 0);

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++)
				if(map[i][j])
				map[i][j] = map[i][j] > 2 ? 0 : 1;

		bool ok = false;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				if (map[i][j]) ok = true;
			
		if (!ok) {
			printf("%d", ret);
			return 0;
		}
	}
}
