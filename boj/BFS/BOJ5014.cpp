//BOJ
//ID : 5014 / BFS
//2017/08/12

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int F, S, G, u[2];
int cost[1000001];

int main() {
	
	memset(cost, -1, sizeof(cost));
	scanf("%d%d%d%d%d", &F, &S, &G, &u[0], &u[1]);
	u[1] = -u[1];
	queue<int> q;
	q.push(S);
	cost[S] = 0;
	bool ok = false;

	while (!q.empty()) {
		int here = q.front(); q.pop();
		
		if (here == G) {
			ok = true;
			break;
		}

		for (int i = 0; i < 2; i++) {
			int t = here + u[i];
			if (1 <= t && t <= F && cost[t] == -1) {
				cost[t] = cost[here] + 1;
				q.push(t);
			}
		}
	}

	if (ok) printf("%d", cost[G]);
	else puts("use the stairs");
}