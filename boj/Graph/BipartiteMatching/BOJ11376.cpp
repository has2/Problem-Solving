#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N,M,cap[2002][2002], flow[2002][2002];
vector<int> adj[2002];
int S = 0,T;

int main() {

	scanf("%d%d", &N, &M);
	T = N + M + 1;
	for (int i = 1; i <= N; i++) {
		int k, l;
		scanf("%d", &k);
		while (k--) {
			scanf("%d", &l);
			l = N + l;
			cap[i][l] = 1;
			adj[i].push_back(l);
			adj[l].push_back(i);
		}
		cap[S][i] = 2;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = N + 1; i <= N + M; i++) {
		cap[i][T] = 1;
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	
	int total = 0;
	while (true) {

		vector<int> par(N + M + 2, -1);
		queue<int> Q;
		Q.push(S);
		par[S] = S;
		while (!Q.empty() && par[T] == -1) {
			int from = Q.front(); Q.pop();
			for (int to : adj[from]) {
				if (cap[from][to] - flow[from][to] > 0 && par[to] == -1) {
					Q.push(to);
					par[to] = from;
				}
			}
		}

		if (par[T] == -1) break;

		for (int p = T; p != S; p = par[p]) {
			flow[par[p]][p]++;
			flow[p][par[p]]--;
		}
		total++;
	}

	printf("%d\n", total);
}

