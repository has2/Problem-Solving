#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

const int inf = 987654321;
using namespace std;
vector <vector<pair<int, int>>> adj;
vector <int> dist;
vector <int> via;
vector <bool> ans;
vector <int> cnt;

int V, E, u, v, c;

void dijkstra(int start) {

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	
	while (!pq.empty()) {
		
		int from = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (dist[from] < d) continue;

		for (auto &to : adj[from]) {
			
			int adjdist = to.second;
			int To = to.first;

			if (dist[To] > dist[from] + adjdist) {
				dist[To] = dist[from] + adjdist;
				pq.push(make_pair(-dist[To], To));
			}
		}
	}

}

int main(int argc, char** argv)
{
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d%d", &V, &E);
		adj.clear(); ans.clear();
		adj.resize(V + 1); ans.resize(V+1);

		while (E--) {
			scanf("%d%d%d", &u, &v, &c);
			adj[u].push_back(make_pair(v, c));
			adj[v].push_back(make_pair(u, c));
		}

		for (int i = 1; i <= V; i++) {
			dist.resize(V + 1, inf); via.resize(V + 1); cnt.resize(V + 1);
			dijkstra(i);
			for (int j = 1; j <= V; j++) {

				for (auto &edge : adj[j]) {
					int To = edge.first;
					int adjdist = edge.second;
					if (dist[j] == dist[To] + adjdist) {
						via[j] = To;
						cnt[j]++;
					}
				}
			}

			for (int v = 1; v <= V; v++) {
				if (cnt[v] == 1 && via[v] != i) {
					ans[via[v]] = true;
				}
			}
			dist.clear(); via.clear(); cnt.clear();
		}

		vector<int> ansvec;
		int anscnt=0;
		for (int i = 1; i <= V; i++) {
			if (ans[i]) {
				ansvec.push_back(i);
				anscnt++;
			}
		}

		printf("Case#%d\n%d", test_case + 1,anscnt);
		for (auto a : ansvec) {
			printf(" %d", a);
		}
		printf("\n");
	}

	return 0;
}