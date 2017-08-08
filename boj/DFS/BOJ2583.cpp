//BOJ
//ID : 2583 / DFS
//2017/08/02

#include <cstdio>
#include <algorithm>
#include <vector>

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };

int m,n,k,map[102][102],cnt;

void dfs(int y,int x) {
	
	map[y][x] = 0;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (map[ty][tx]) dfs(ty, tx);
	}

}

int main() {
	
	scanf("%d%d%d", &m, &n, &k);

	for (int y = 1; y <= m; y++)
		for (int x = 1; x <= n; x++)
			map[y][x] = 1;

	while (k--) {

		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1++; y1++;
		for (int i = y1; i <= y2; i++)
			for (int j = x1; j <= x2; j++)
				map[i][j] = 0;
	}
		
	std::vector<int> ret;

	for(int y=1;y<=m;y++)
		for (int x = 1; x <= n; x++) {
			if (map[y][x]) {
				cnt = 0;
				dfs(y, x);
				ret.push_back(cnt);
			}
		}

	printf("%d\n", ret.size());
	std::sort(ret.begin(), ret.end());
	for (int v : ret)
		printf("%d ", v);
}