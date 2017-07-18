#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N,cap[52][52], flow[52][52];

int ctoi(int ch) {
	if (ch <= 'Z') return ch - 'A';
	return ch - 'a' + 26;
}

int nf(int src, int sink) {

	memset(flow, 0, sizeof(flow));
	int total = 0;
	

	while (true) {
		vector<int> par(52, -1);
		queue<int> q;
		par[src] = src;
		q.push(src);
		while (!q.empty() && par[sink] == -1) {
			int here = q.front(); q.pop();

			for (int there = 0; there < 52; there++) {
				if (cap[here][there] - flow[here][there] > 0 && par[there] == -1) {
					q.push(there);
					par[there] = here;
				}
			}
		}

		if (par[sink] == -1) break;

		int amt = INF;

		for (int i = sink; i != src; i = par[i])
			amt = min(cap[par[i]][i] - flow[par[i]][i], amt);

		for (int i = sink; i != src; i = par[i]) {
			flow[par[i]][i] += amt;
			flow[i][par[i]] -= amt;
		}
		total += amt;
	}
	return total;
}


int main(void) {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char a, b;
		int c;
		scanf(" %c %c %d", &a, &b,&c);
		a = ctoi(a); b = ctoi(b);
		cap[a][b] += c;
	}

	printf("%d\n", nf(0, 25));
}
