#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

vector<int> adj[10001]; 
vector<int> adj_r[10001];
int visited[10001], visited_r[10001];
int order[10001],cnt=0,scc_n;
vector<int> scc[10001];


void dfs(int n) {

	visited[n] = 1;

	for (int i = 0; i < adj[n].size(); i++) {
		if (visited[adj[n][i]] == 0)
			dfs(adj[n][i]);
	}

	cnt++;
	order[cnt] = n;
	
}

void dfs_r(int n) {

	visited_r[n] = 1;

	for (int i = 0; i < adj_r[n].size(); i++) {
		if (visited_r[adj_r[n][i]] == 0)
			dfs_r(adj_r[n][i]);
	}

	scc[scc_n].push_back(n);
	
}


int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj_r[b].push_back(a);
	}
	
	for (int i = 1; i <= V; i++) {
		if(visited[i]==0)
		dfs(i);
	}

	for (int i = cnt; i > 0; i--) {
		if (visited_r[order[i]] == 0) {
			dfs_r(order[i]);
			scc_n++;
		}
	}

	printf("%d\n", scc_n);

	for (int i = 0; i < scc_n; i++) 	
	sort(scc[i].begin(), scc[i].end());

	priority_queue<pair<int, int>> pq;
	pair<int, int> scc_order[10001];
	for (int i = 0; i < scc_n; i++) {
		scc_order[i].first = -scc[i][0];
		scc_order[i].second = i;
		pq.push(scc_order[i]);
	}
	


	int curr;
	for (int i = 0; i < scc_n; i++) {
		curr = pq.top().second;
		pq.pop();
		for (int j = 0; j < scc[curr].size(); j++) {
			printf("%d ", scc[curr][j]);
		}
		printf("-1\n");
	}

}
