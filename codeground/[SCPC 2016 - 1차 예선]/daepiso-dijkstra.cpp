#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;
const long long inf = numeric_limits<long long>::max();

struct Edge {
	int to;
	long long cost;
	Edge(int to, long long cost) : to(to), cost(cost) {}
};

vector<Edge> adj[100001];
vector<int> room;
vector<long long> dist;
vector<int> starting_pt;
int V, E, K;

void dijkstra() {

	priority_queue<pair<long long, int>> pq;	

	for (auto r : room) {
		pq.push(make_pair(0, r));
		dist[r] = 0;
		starting_pt[r] = r;
	}

	while (!pq.empty()) {

		int here = pq.top().second;
		long long mindist = -pq.top().first;

		pq.pop();
		if (mindist > dist[here]) continue;

		for (auto there : adj[here]) {
			if (dist[there.to] > dist[here] + there.cost) {
				dist[there.to] = dist[here] + there.cost;
				starting_pt[there.to] = starting_pt[here];
				pq.push(make_pair(-dist[there.to], there.to));
			}
			else if (dist[there.to] == dist[here] + there.cost) {
				if (starting_pt[there.to] < starting_pt[here]) {
					starting_pt[there.to] = starting_pt[here];
					pq.push(make_pair(-dist[there.to],there.to));
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		long long sum_dis = 0,sum_num = 0;
		cin >> V >> E >> K;

		for(int i=1;i<=V;i++)
			adj[i].clear();
		room.clear(); dist.clear(); starting_pt.clear();
		dist.resize(V+1,inf); starting_pt.resize(V+1);

		while (E--) {
			int u,v,c;
			cin >> u >> v >> c;
			adj[u].push_back(Edge(v, c));
			adj[v].push_back(Edge(u, c));
		}
		for (int i = 0; i < K; i++) {
			int k;
			cin >> k;
			room.push_back(k);
		}

		dijkstra();
		for (int i = 1; i <= V; i++) {
			sum_dis += dist[i];
			sum_num += starting_pt[i];
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << sum_dis << endl << sum_num << endl;
	}
	return 0;
}