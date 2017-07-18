#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct shark {
	int a, b, c;
	shark(){}
	shark(int a,int b,int c):a(a),b(b),c(c){}
};

int n,S=0,E;
int cap[1002][1002], flow[1002][1002];
shark Sh[1002];
vector<int> adj[1002];


int NF() {

	int total = 0;

	while (true) {

		vector<int> par(2*n + 2,-1);
		queue<int> q;

		q.push(S);
		par[S] = S;
		while (!q.empty() && par[E] == -1) {
			int here = q.front(); q.pop();
			for (int there : adj[here]) {
				if (par[there] == -1 && cap[here][there] - flow[here][there] > 0) {
					par[there] = here;
					q.push(there);
				}
			}
		}
		if (par[E] == -1) break;

		for (int p = E; p != S; p = par[p]) {
			flow[par[p]][p]++;
			flow[p][par[p]]--;
		}

		total++;
	}
	return total;
}

int main() {

	scanf("%d", &n);
	E = 2*n+1;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Sh[i] = shark(a, b, c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && Sh[i].a >= Sh[j].a && Sh[i].b >= Sh[j].b && Sh[i].c >= Sh[j].c) {
				cap[i][n+j] = 1;
				adj[i].push_back(n+j); adj[n+j].push_back(i);
				if (Sh[i].a == Sh[j].a && Sh[i].b == Sh[j].b && Sh[i].c == Sh[j].c && i < j)
					cap[i][j] = 0;
			}
		}
		cap[S][i] = 2;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}


	for (int i = 1; i <= n; i++) {
		cap[n+i][E] = 1;
		adj[n+i].push_back(E);
		adj[E].push_back(n+i);
	}

	printf("%d\n",n-NF());
}
