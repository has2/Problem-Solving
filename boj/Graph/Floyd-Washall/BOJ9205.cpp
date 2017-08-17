//BOJ
//ID : 9205 / Floyd-Warshall,Dijkstra
//2017/08/17

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int INF = 987654321;
int n;
pair<int, int> p[103];
int dist[103][103];

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {

		scanf("%d", &n);
		memset(dist, 0, sizeof(dist));

		for (int i = 1; i <= n + 2; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			p[i] = make_pair(x, y);
		}

		for (int i = 1; i <= n + 2; i++)
			for (int j = 1; j <= n + 2; j++) {
				int diff = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
				dist[i][j] = dist[j][i] = diff <= 1000 ? diff : INF;
			}

		for (int k = 1; k <= n + 2; k++)
			for (int i = 1; i <= n + 2; i++)
				for (int j = 1; j <= n + 2; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		if (dist[1][n + 2] == INF) puts("sad");
		else puts("happy");
	}
}

//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//#include <cstring>
//#include <vector>
//#include <queue>
//using namespace std;
//const int INF = 987654321;
//int n;
//pair<int,int> p[103];
//vector<pair<int, int>> adj[103];
//int dist[103];
//
//int main() {
//	int c;
//	scanf("%d", &c);
//	while (c--) {
//
//		scanf("%d", &n);
//		memset(dist, 0, sizeof(dist));
//		for (int i = 1; i <= n + 2; i++)
//			adj[i].clear();
//
//		for (int i = 1; i <= n + 2; i++) {
//			int x, y;
//			scanf("%d%d", &x, &y);
//			p[i] = make_pair(x, y);
//		}
//
//		for (int i = 1; i <= n + 2; i++)
//			for (int j = 1; j <= n + 2; j++) {
//				int diff = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
//				if (diff <= 1000) {
//					adj[i].push_back(make_pair(j, diff));
//					adj[j].push_back(make_pair(i, diff));
//				}
//			}
//
//
//		fill(dist + 1, dist + n + 3, INF);
//		priority_queue<pair<int,int>> pq;
//		pq.push(make_pair(0,1));
//		dist[1] = 0;
//
//		while (!pq.empty()) {
//			int here = pq.top().second;
//			int cost = -pq.top().first;
//			pq.pop();
//
//			for (auto there : adj[here]) {
//				int next = there.first;
//				int nextDist = there.second + cost;
//				if (dist[next] > nextDist) {
//					dist[next] = nextDist;
//					pq.push(make_pair(-nextDist, next));
//				}
//			}
//		}
//
//		if (dist[n + 2] == INF) puts("sad");
//		else puts("happy");
//		
//	}
//}






