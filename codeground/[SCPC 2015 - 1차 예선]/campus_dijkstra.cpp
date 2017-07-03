#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;

vector <vector<pair<int, int>>> edge;
vector<bool> found;
vector<bool> possible;
vector<int> dist;
vector<int> path;
vector<int> cnt;

void getpos(int start, int end,int N) {

	int cur = path[end],min = dist[end];
	if (min == INF) return;

	while (start != cur) {
		possible[cur] = true;
		cur = path[cur];
	}
	
	for (auto li : edge[end]) {
		int u = li.first;
		int d = li.second;
		if (u != start && dist[u] + d == min)
			possible[u] = true;
	}
}

void dijkstra(int start, int N) {

	int here, fixDis;
	path[start] = start;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		here = pq.top().second;
		fixDis = -pq.top().first;
		pq.pop();
		if (fixDis > dist[here]) continue;

		for (auto there : edge[here]) {
			int v = there.first;
			int d = there.second;
			if (dist[v] > dist[here] + d) {
				dist[v] = dist[here] + d;
				pq.push(make_pair(-dist[v], v));
				path[v] = here;
			}
		}
	}
}

int main(void) {

	int T, N, M,k,i,u,v,c,j;
	scanf("%d", &T);
	for (k = 1; k <= T;k++) {

		edge.clear(); found.clear(); dist.clear(); path.clear(); possible.clear(); cnt.clear();
		scanf("%d%d", &N, &M);
		edge.resize(N + 1); found.resize(N + 1); dist.resize(N + 1,INF); path.resize(N + 1); possible.resize(N + 1,false); cnt.resize(N + 1);
		
		while (M--) {
			scanf("%d%d%d", &u, &v, &c);
			edge[u].push_back(make_pair(v, c));
			edge[v].push_back(make_pair(u, c));
			cnt[u]++; cnt[v]++;
		}
		
		for (i = 1; i <= N; i++) {
			dijkstra(i, N);
			for (j = 1; j <= N; j++) {
				if(i!=j)
					getpos(i,j,N);
			}
			found.clear(); dist.clear(); path.clear();
			found.resize(N + 1,false); dist.resize(N + 1,INF); path.resize(N + 1);
		}

		for (i = 1; i <= N; i++) 
			if (cnt[i] < 2) 
				possible[i] = false;
		
		printf("Case #%d\n", k);

		int num = 1;
		for (i = 1; i <= N; i++) {
			if (!possible[i]) {
				cnt[num++] = i;
			}
		}

		printf("%d ", num - 1);
		for (i = 1; i < num; i++) 
			printf("%d ", cnt[i]);
		printf("\n");
	}

	return 0;
}