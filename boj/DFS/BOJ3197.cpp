//BOJ
//ID : 3197 // dfs,bfs
//2017/10/04

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int n, m,by[2],bx[2],k,day=1,map[1502][1502];
int visit[1502][1502];
queue<pair<int,int>> melt;

bool bfs(int d) {
	                                                                                     
	queue<pair<int, int>> q;

	q.push(make_pair(by[0], bx[0]));
	visit[by[0]][bx[1]] = 1;

	while (!q.empty()) {

		int hy = q.front().first;
		int hx = q.front().second;
		q.pop();
		if (hy == by[1] && hx == bx[1]) return 1;

		for (int i = 0; i < 4; i++) {
			int ty = hy + dy[i], tx = hx + dx[i];
			if (map[ty][tx] == -1 || visit[ty][tx] || map[ty][tx] > d + 1) continue;
			q.push(make_pair(ty, tx));
			visit[ty][tx] = 1;
		}
	}
	return 0;
}

void dfs2(int y, int x) {

	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (map[ty][tx] == -1) continue;
		if (map[ty][tx] == 1) {
			map[ty][tx] = day + 1;
			melt.push(make_pair(ty, tx));
			visit[ty][tx] = 1;
		}
		else if (!visit[ty][tx]) dfs2(ty, tx);
	}
}

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
				map[i][j] = -1;
				continue;
			}
			char ch;
			scanf(" %c", &ch);
			if (ch == 'L') {
				map[i][j] = 0;
				by[k] = i, bx[k++] = j;
			}
			else if (ch == '.') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!visit[i][j] && !map[i][j]) dfs2(i, j);

	while (!melt.empty()) {
		day++;
		int vsize = melt.size();
		while (vsize--) {
			int hy = melt.front().first;
			int hx = melt.front().second;
			melt.pop();

			for (int j = 0; j < 4; j++) {
				int ty = hy + dy[j], tx = hx + dx[j];
				if (map[ty][tx] == 1) {
					map[ty][tx] = day + 1;
					melt.push(make_pair(ty, tx));
				}
			}
		}
	}

	int lo = -1, hi = day + 1,mid;
	while (lo + 1 < hi) {

		mid = (lo + hi) / 2;
		memset(visit, 0, sizeof(visit));
		bool ok = bfs(mid);

		if (ok) hi = mid;
		else lo = mid;
	}
	printf("%d", hi);
}