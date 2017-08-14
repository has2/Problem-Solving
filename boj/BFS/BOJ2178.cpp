//BOJ
//ID : 2178 / BFS
//2017/08/12

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int n, m,map[102][102],cost[102][102];
char t[100];

int main() {
	scanf("%d%d", &n, &m);

	for (int y = 1; y <= n; y++) {
		scanf("%s", t);
		for (int x = 1; x <= m; x++)
			map[y][x] = t[x - 1]-'0';
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	map[1][1] = 0;
	cost[1][1] = 1;
	while (!q.empty()) {
		pair<int,int> here = q.front(); q.pop();
		int y = here.first, x = here.second;

		if (y == n && x == m) {
			printf("%d", cost[y][x]);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i], tx = x + dx[i];
			if (map[ty][tx]) {

				q.push(make_pair(ty, tx));
				map[ty][tx] = 0;
				cost[ty][tx] = cost[y][x] + 1;
			}
		}
	}
}