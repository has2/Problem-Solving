//BOJ
//ID : 3977 / SCC
//2017/08/09

#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int n, m;
int sccId[MAX], sccIndegree[MAX], dfsn[MAX],sccNum, vCnt;
bool fin[MAX];
stack<int> s;
vector<int> adj[MAX];

int scc(int here) {

	int ret = dfsn[here] = ++vCnt;
	s.push(here);

	for (int there : adj[here]) {

		if (!dfsn[there]) ret = min(ret, scc(there));
		else if (!fin[there]) ret = min(ret, dfsn[there]);
	}

	if (ret == dfsn[here]) {

		while (1) {
			int cur = s.top();
			s.pop();
			sccId[cur] = sccNum;
			fin[cur] = true;
			if (cur == here) break;
		}
		sccNum++;
	}
	return ret;
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {

		scanf("%d%d", &n, &m);

		for (int i = 0; i < n; i++)
			adj[i].clear();
		memset(sccId, 0, sizeof(sccId));
		memset(sccIndegree, 0, sizeof(sccIndegree));
		memset(dfsn, 0, sizeof(dfsn));
		memset(fin, 0, sizeof(fin));
		sccNum = vCnt = 0;

		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}

		for (int i = 0; i < n; i++) 
			if (!fin[i]) scc(i);
		
		for (int i = 0; i < n; i++) {
			int sid = sccId[i];
			for (int j : adj[i]) {
				int jid = sccId[j];
				if (sid != jid) sccIndegree[jid]++;
			}
		}

		int indcnt = 0,sol_id;

		for (int i = 0; i < sccNum; i++)
			if (sccIndegree[i] == 0) indcnt++;

		if (indcnt != 1) {
			printf("Confused\n\n");
			continue;
		}
		
		for (int i = 0; i < sccNum; i++) {
			if (sccIndegree[i] == 0) {
				sol_id = i;
				break;
			}
		}

		vector<int> ret;

		for (int i = 0; i < n; i++) 
			if (sccId[i] == sol_id) ret.push_back(i);
		sort(ret.begin(), ret.end());

		for (int v : ret)
			printf("%d\n", v);
		printf("\n");
	}
}
