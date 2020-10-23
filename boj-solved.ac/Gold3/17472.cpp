#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct P {
	int cost, u, v;
};

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N,M,map[11][11];
bool visit[11][11];
vector<pair<int, int>> groups[7];
int dist[7][7],INF=987654321;
int uf[7];

void dfs(int y, int x, int g) {
	groups[g].push_back({ y,x });
	visit[y][x] = 1;
	map[y][x] = g;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] ==0 || visit[ny][nx]) continue;
		dfs(ny, nx, g);
	}
}

bool cmp(P& a, P& b) {
	return a.cost < b.cost;
}

int find(int a) {
	if (a == uf[a]) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return false;
	uf[pa] = pb;
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);

	int group = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0 && !visit[i][j]) {
				group++;
				dfs(i, j, group);
			}
		}
	}

	for (int i = 1; i <= group; i++) 
		for (int j = 1; j <= group; j++) dist[i][j] = INF;

	for (int i = 1; i <= group; i++) {
		auto pairs = groups[i];

		for (auto p : pairs) {
			int y = p.first;
			int x = p.second;

			int cnt = 0;
			int ny = y;
			while (1) {
				ny++;
				if (ny >= N) break;
				if (map[ny][x] == map[y][x]) {
					cnt = 0;
					continue;
				}
				if (map[ny][x] == 0) {
					cnt++;
					continue;
				}
				if (map[ny][x] > 0) {
					if (cnt > 1) {
						dist[map[y][x]][map[ny][x]] = min(cnt, dist[map[y][x]][map[ny][x]]);
					}
					break;
				}
			}

			cnt = 0;
			int nx = x;
			while (1) {
				nx++;
				if (nx >= M) break;
				if (map[y][nx] == map[y][x]) {
					cnt = 0;
					continue;
				}
				if (map[y][nx] == 0) {
					cnt++;
					continue;
				}
				if (map[y][nx] > 0) {
					if (cnt > 1) {
						dist[map[y][x]][map[y][nx]] = min(cnt, dist[map[y][x]][map[y][nx]]);
					}
					break;
				}
			}
		}
	}
	vector<P> edges;
	for (int i = 1; i <= group; i++) {
		for (int j = 1; j <= group; j++) {
			if (dist[i][j] != INF) {
				edges.push_back({ dist[i][j],i,j });
			}
		}
		uf[i] = i;
	}
	sort(edges.begin(), edges.end(), cmp);

	int cnt = 0;
	int cost = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (merge(edges[i].u, edges[i].v)) {
			cost += edges[i].cost;
			if (++cnt == group-1) break;
		}
	}
	printf("%d", cnt < group-1 ? -1 : cost);
}