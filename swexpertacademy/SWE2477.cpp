//SW Expert
//ID : 2477 // priority queue
//2017/10/08

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k,jsnum,jbnum;
int js[10], jb[10],t[1001];

int main() {

	int tcase;
	scanf("%d", &tcase);
	for (int tc = 1; tc <= tcase; tc++) {

		scanf("%d%d%d%d%d", &n, &m, &k, &jsnum, &jbnum);
		int customer = k;
		for (int i = 1; i <= n; i++) scanf("%d", &js[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &jb[i]);
		for (int i = 1; i <= k; i++) scanf("%d", &t[i]);

		pair<int, int> jsc[10], jbc[10];
		pair<int, int> Info[1001];
		priority_queue<int> jspq;
		priority_queue<pair<pair<int, int>, int>> jbpq;
		int curidx = 1;
		for (int time = 0;; time++) {

			for (int j = curidx; j <= k; j++) {
				if (t[j] == time) {
					jspq.push(-j);
				}
				else {
					curidx = j;
					break;
				}
			}

			for (int i = 1; i <= n; i++) {
				if (jsc[i].first == 0) {
					if (jspq.empty()) continue;
					jsc[i].first = -jspq.top(); jspq.pop();
					jsc[i].second = js[i];
					Info[jsc[i].first].first = i;
				}
				else if (--jsc[i].second == 0) {

					jbpq.push(make_pair(make_pair(-time, -i), jsc[i].first));
					jsc[i].first = 0;
					if (jspq.empty()) continue;
					jsc[i].first = -jspq.top(); jspq.pop();
					jsc[i].second = js[i];
					Info[jsc[i].first].first = i;
				}
			}

			for (int i = 1; i <= m; i++) {
				if (jbc[i].first == 0) {
					if (jbpq.empty()) continue;
					jbc[i].first = jbpq.top().second; jbpq.pop();
					jbc[i].second = jb[i];
					Info[jbc[i].first].second = i;
					customer--;
				}
				else if (--jbc[i].second == 0) {
					jbc[i].first = 0;
					if (jbpq.empty()) continue;
					jbc[i].first = jbpq.top().second; jbpq.pop();
					jbc[i].second = jb[i];
					Info[jbc[i].first].second = i;
					customer--;
				}
			}
			if (customer == 0) break;
		}
		int ret = 0;
		for (int i = 1; i <= k; i++)
			if (jsnum == Info[i].first && jbnum == Info[i].second) ret += i;

		if (ret == 0) ret = -1;
		printf("#%d %d\n",tc,ret);
	}
}