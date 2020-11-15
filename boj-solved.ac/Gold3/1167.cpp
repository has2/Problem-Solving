#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int N,maxV,maxLen;
vector<pair<int, int>> adj[100001];
bool visit[100001];

void dfs(int n,int len) {

	visit[n] = 1;
	if (maxLen < len) {
		maxV = n;
		maxLen = len;
	}

	for (auto k : adj[n]) {
		int next = k.first;
		int dist = k.second;
		if (!visit[next]) {
			dfs(next, len + dist);
		}
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int v,a,b;
		scanf("%d", &v);
		while (1) {
			scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			adj[v].push_back({ a,b });
		}
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	dfs(maxV, 0);
	printf("%d\n", maxLen);
}