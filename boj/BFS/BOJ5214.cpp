//BOJ
//ID : 13335 // simultation
//2017/10/18

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, k, m,ret;
bool visit[100001];
vector<int> tube[100001];
vector<int> reach[1000];

int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int node;
			scanf("%d", &node);
			tube[node].push_back(i);
			reach[i].push_back(node);
		}
	}

	queue<int> q;
	q.push(1);
	visit[1] = 1;


	while (!q.empty()) {

		int qsize = q.size();
		ret++;
		while (qsize--) {

			int hnode = q.front(); q.pop();
			if (hnode == n) {
				printf("%d", ret);
				return 0;
			}
			vector<int> htube = tube[hnode];
			
			for (int tnum : htube) {
				for (int nnode : reach[tnum]) {
					if (visit[nnode]) continue;
					q.push(nnode);
					visit[nnode] = 1;
				}
			}
		}
	}
}
