//BOJ
//ID : 2152 / SCC
//2017/08/09
//시작점이 아닌 indegree가 0인 부분도 추가해줘야(정상적으로 위상정렬) 메모리 초과 안남

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 10000;
int n, m,s,t,scc_s,scc_t;
int ret[MAX], sccNum[MAX],sccId[MAX],dfsn[MAX], sccIndegree[MAX], sccCnt, vCnt;
bool fin[MAX],reach[MAX];
vector<int> adj[MAX];
vector<int> scc_adj[MAX];
stack<int> S;

int scc(int here) {

	int ret = dfsn[here] = ++vCnt;
	S.push(here);

	for (int there : adj[here]) {
		if (!dfsn[there]) ret = min(ret, scc(there));
		else if (!fin[there]) ret = min(ret, dfsn[there]);
	}

	if (ret == dfsn[here]) {

		while (1) {
			int cur = S.top();
			S.pop();
			fin[cur] = 1;
			sccId[cur] = sccCnt;

			if (cur == here) break;
		}
		sccCnt++;
	}
	return ret;
}

int main() {
	

	scanf("%d%d%d%d", &n, &m, &s, &t);
	s--; t--;
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u - 1].push_back(v - 1);
	}

	for (int i = 0; i < n; i++)
		if (!dfsn[i]) scc(i);

	for (int i = 0; i < n; i++) {

		int si = sccId[i];
		sccNum[si]++;
		if (i == s) scc_s = si;
		if (i == t) scc_t = si;

		for (int j : adj[i])
			if (si != sccId[j]) {
				scc_adj[sccId[i]].push_back(sccId[j]);
				sccIndegree[sccId[j]]++;
			}
	}
			
	queue<int> q;

	for (int i = 0; i < sccCnt; i++) {
		ret[i] = sccNum[i];

		if (scc_s == i) reach[i] = true;
		if (!sccIndegree[i]) q.push(i);
	}

	while (!q.empty()) {

		int here = q.front();
		q.pop();

		for (int there : scc_adj[here]) {

			if (reach[here]) {
				ret[there] = max(ret[there], ret[here] + sccNum[there]);
				reach[there] = true;
			}
			if (--sccIndegree[there] == 0) q.push(there);
		}
	}
	printf("%d\n", reach[scc_t] ? ret[scc_t] : 0);
}
