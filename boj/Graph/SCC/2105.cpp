//BOJ
//ID : 2105 / SCC
//2017/08/07

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10000;
vector<int> adj[MAX+1];
int dfsn[MAX+1];
int V, E,cnt,sccCnt;
bool finished[MAX+1];
stack<int> S;
vector<vector<int>> Scc;

int scc(int here) {

	int ret = dfsn[here] = ++cnt;
	S.push(here);
	for (auto there : adj[here]) {

		if (!dfsn[there]) 
			ret = min(ret, scc(there));
		else if (!finished[there])
			ret = min(ret, dfsn[there]);

	}

	if (ret == dfsn[here]) {

		vector<int> sccCur;

		while (1) {
			int cur = S.top();
			S.pop();
			sccCur.push_back(cur);
			finished[cur] = true;
			if (cur == here) break;
		}
		sccCnt++;
		sort(sccCur.begin(), sccCur.end());
		Scc.push_back(sccCur);
	}
	return ret;
}


int main() {

	scanf("%d%d", &V, &E);

	for (int i = 0; i < E; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u-1].push_back(v-1);
	}

	for (int i = 0; i < V; i++) {
		if (!dfsn[i])
			scc(i);
	}

	sort(Scc.begin(), Scc.end());

	printf("%d\n", Scc.size());
	for (auto ps : Scc) {
		for (auto v : ps)
			printf("%d ",v+1);
		printf("-1\n");
	}
}
