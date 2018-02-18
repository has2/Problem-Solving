//BOJ
//ID : 13335 // simultation
//2017/10/18

#include <cstdio>
#include <queue>
using namespace std;
int n, w, l,weight[1000],curw;
struct T{ int tnum, et; };
int main() {
	scanf("%d%d%d", &n, &w, &l);
	for (int i = 0; i < n; i++) scanf("%d", &weight[i]);

	int cidx = 0;
	queue<T> q;
	for (int time = 1;; time++) {
		if (!q.empty() && q.front().et == time) {
			if (q.front().tnum == n - 1) {
				printf("%d", time);
				return 0;
			}
			curw -= weight[q.front().tnum];
			q.pop();
		}

		if (curw + weight[cidx] > l) continue;
		curw += weight[cidx];
		q.push({ cidx,time + w });
		cidx++;
	}
}
