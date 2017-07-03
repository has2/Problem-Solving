#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;

vector < vector<pair<int, int>>> edge;
vector < pair<int, int>> edge_del;

int before_path[500];

void change_cost(int start, int end) {
	int cur = end;
	for (int i = 0; i < edge[before_path[cur]].size(); i++) {
		if (edge[before_path[cur]][i].first == cur) {
			edge[before_path[cur]][i].second = INF;
			break;
		}
	}
	cur = before_path[cur];
	while (start != cur) {
		edge_del.push_back(make_pair(before_path[cur], cur));
		cur = before_path[cur];
	}
}

void delete_all() {
	int a, b;
	for (auto a_b : edge_del) {
		a = a_b.first;
		b = a_b.second;
		for (auto& eg : edge[a]) {
			if (eg.first == b)
				eg.second = INF;
		}
	}
}

vector<int> dijkstra(int start, int N) {

	int here, fixDis;
	before_path[start] = start;
	vector<int> dis(N, INF);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dis[start] = 0;

	while (!pq.empty()) {
		here = pq.top().second;
		fixDis = -pq.top().first;
		pq.pop();
		if (fixDis > dis[here]) continue;

		for (auto there : edge[here]) {
			int v = there.first;
			int d = there.second;
			if (dis[v] > dis[here] + d) {
				dis[v] = dis[here] + d;
				pq.push(make_pair(-dis[v], v));
				before_path[v] = here;
			}
		}
	}
	return dis;
}

int main(void) {

	int N, M, S, E, a, b, c, min, ans;

	while (true) {

		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0) break;
		scanf("%d%d", &S, &E);
		edge.clear();
		edge_del.clear();
		edge.resize(N);

		while (M--) {
			scanf("%d%d%d", &a, &b, &c);
			edge[a].push_back(make_pair(b, c));
		}

		vector<int> res = dijkstra(S, N);
		min = res[E];
		if (min == INF)
			ans = -1;
		else {
			while (true) {
				change_cost(S, E);
				res = dijkstra(S, N);
				if (res[E] > min) {
					delete_all();
					res = dijkstra(S, N);
					ans = res[E] != INF ? res[E] : -1;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}