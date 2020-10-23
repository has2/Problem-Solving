#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,V[501], In[501],maxv[501];
vector<int> adj[501];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int c, u;
		scanf("%d", &c);
		V[i] = c;
		while (1) {
			scanf("%d", &u);
			if (u == -1) break;
			adj[u].push_back(i);
			In[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) if (In[i] == 0) q.push(i);

	for (int i = 0; i < N; i++) {
		int cur = q.front(); q.pop();
		for (auto next : adj[cur]) {
			In[next]--;
			maxv[next] = max(maxv[next], maxv[cur] + V[cur]);
			if (In[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) printf("%d\n", maxv[i]+V[i]);
}