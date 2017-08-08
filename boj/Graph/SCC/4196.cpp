//BOJ
//ID : 4196 / SCC
//2017/08/07

#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
const int MAX = 100000;
int n, m;
int Vcnt,Scnt, dfsn[MAX + 1], fin[MAX + 1], Snum[MAX + 1];
int indegree[MAX];
vector<int> adj[MAX + 1];
stack<int> S;

int scc(int here) {

	int ret = dfsn[here] = ++Vcnt;
	S.push(here);

	for (int there : adj[here]) {

		if (!dfsn[there]) ret = min(ret, scc(there));
		else if (!fin[there]) ret = min(ret, dfsn[there]);
	}

	if (ret == dfsn[here]) {

		while (1) {

			int cur = S.top();
			S.pop();
			Snum[cur] = Scnt;
			fin[cur] = 1;
			if (cur == here) break;
		}
		Scnt++;
	}
	return ret;
}


int main() {

	int c;
	scanf("%d", &c);
	while (c--) {
		while (!S.empty())
		S.pop();
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}

		Vcnt = Scnt = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(fin, 0, sizeof(fin));
		memset(Snum, 0, sizeof(Snum));
		memset(indegree, 0, sizeof(indegree));

		for (int i = 1; i <= n; i++)
			if (!fin[i])
				scc(i);

		for (int i = 1; i <= n; i++) 
			for (int v : adj[i])
				if (Snum[i] != Snum[v]) indegree[Snum[v]]++;

		int ret = 0;
		for (int i = 0; i < Scnt; i++)
			if (!indegree[i]) ret++;

		printf("%d\n", ret);
	}
}