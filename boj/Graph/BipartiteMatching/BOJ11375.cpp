#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1000;
const int MAX_V = 1000 * 2 + 2;
const int S = MAX_V - 2;
const int E = MAX_V - 1;
int cap[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int N, M;
vector<int> adj[MAX_V];

int NF(int src, int sink) {

	int total = 0;

	while (true) {
		vector<int> par(MAX_V, -1);
		queue<int> Q;
		Q.push(src);
		par[src] = src;
		while (!Q.empty() && par[sink] == -1) {
			int here = Q.front(); Q.pop();
			for (int there : adj[here]) {
				if (cap[here][there] - flow[here][there] > 0 && par[there] == -1)
				{
					par[there] = here;
					Q.push(there);
				}
			}
		}

		if (par[sink] == -1) break;

		for (int node = sink; node != src; node = par[node]) {
			flow[par[node]][node] += 1;
			flow[node][par[node]] -= 1;
		}

		total++;
	}
	return total;
}

int main() {

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int c, m;
		scanf("%d", &c);
		while (c--) {
			scanf("%d", &m);
			m = MAX_N + m - 1;
			cap[i][m] = 1;
			adj[i].push_back(m);
			adj[m].push_back(i);
		}
		cap[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
    
	for (int i = MAX_N; i < MAX_N + M; i++) {
		cap[i][E] = 1;
		adj[i].push_back(E);
		adj[E].push_back(i);
	}


	printf("%d\n", NF(S, E));

}