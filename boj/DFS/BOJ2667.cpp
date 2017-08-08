//BOJ
//ID : 2667 / DFS
//2017/08/01

#include <cstdio>
#include <vector>
#include <algorithm>

const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
int n, cnt;
int map[27][27];

void dfs(int y, int x) {

	map[y][x] = 0;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (map[ty][tx]) dfs(ty, tx);
	}
}

int main() {

	scanf("%d", &n);
	char tmp[26];
	for (int i = 1; i <= n; i++) {

		scanf("%s", tmp);
		for (int j = 1; j <= n; j++)
			map[i][j] = tmp[j-1] -'0';
	}

	std::vector<int> ret;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (map[y][x]) {
				cnt = 0;
				dfs(y, x);
				ret.push_back(cnt);
			}
		}
	}
	std::sort(ret.begin(), ret.end());
	printf("%d\n", ret.size());
	for (int r : ret)
		printf("%d\n", r);
}