//BOJ
//ID : 2207 / 2SAT
//2017/08/11
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 20000;
int n, m, dfsn[MAX + 1], fin[MAX + 1], sccId[MAX + 1], vCnt, sCnt;
vector<int> adj[MAX + 1];
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

	scanf("%d%d", &n, &m);
	while (n--) {
		int u, v;
		scanf("%d%d", &u, &v);

		u = u < 0 ? -(2 * u) : 2 * u - 1;
		v = v < 0 ? -(2 * v) : 2 * v - 1;

		int tu, tv;
		tu = u % 2 == 0 ? u - 1 : u + 1;
		tv = v % 2 == 0 ? v - 1 : v + 1;

		adj[tu].push_back(v);
		adj[tv].push_back(u);
	}

	for (int i = 1; i <= 2 * m; i++)
		if (!dfsn[i]) scc(i);

	for (int i = 1; i <= m; i++) {
		if (sccId[2 * i] == sccId[2 * i - 1]) {
			puts("OTL");
			return 0;
		}
	}
	puts("^_^");
}
