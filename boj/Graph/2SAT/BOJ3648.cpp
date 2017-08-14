//BOJ
//ID : 3648 / 2SAT
//2017/08/11
// A가 반드시 참이어야 한다. A V A , ~A -> A
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX = 2000;
int n, m, dfsn[MAX], fin[MAX], sccId[MAX], vCnt, sCnt;
vector<int> adj[MAX];
stack<int> s;

int scc(int here) {

	int ret = dfsn[here] = ++vCnt;
	s.push(here);

	for (int there : adj[here])
		if (!dfsn[there]) ret = min(ret, scc(there));
		else if (!fin[there]) ret = min(ret, dfsn[there]);

	if (ret == dfsn[here]) {
		while (1) {
			int cur = s.top(); s.pop();
			sccId[cur] = sCnt;
			fin[cur] = 1;
			if (here == cur) break;
		}
		sCnt++;
	}
	return ret;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {

		for (int i = 1; i <= 2 * n; i++)
			adj[i].clear();


		adj[2].push_back(1);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			u = u < 0 ? -2 * u : 2 * u - 1;
			v = v < 0 ? -2 * v : 2 * v - 1;

			int tu, tv;
			tu = u % 2 == 0 ? u - 1 : u + 1;
			tv = v % 2 == 0 ? v - 1 : v + 1;
			adj[tu].push_back(v);
			adj[tv].push_back(u);
		}

		for (int i = 1; i <= 2 * n; i++)
			if (!dfsn[i]) scc(i);

		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (sccId[2 * i] == sccId[2 * i - 1]) {
				ok = false;
				break;
			}
		}

		if (ok) puts("yes");
		else puts("no");

		vCnt = 0; sCnt = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(fin, 0, sizeof(fin));
		memset(sccId, 0, sizeof(sccId));
	}
}