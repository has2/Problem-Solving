//BOJ
//ID : 1697 // bfs
//2018/02/19


#include <cstdio>
#include <queue>
using namespace std;
int n, k,ret;

queue<int> Q;
bool visit[100001];

int main(void) {

	scanf("%d%d", &n, &k);
	Q.push(n);
	visit[n] = 1;

	while (1) {

		int qsize = Q.size();
		while (qsize--) {

			int pos = Q.front(); Q.pop();
			if (pos == k) {
				printf("%d", ret);
				return 0;
			}

			if (pos - 1 >= 0 && !visit[pos - 1]) {
				visit[pos - 1] = 1;
				Q.push(pos - 1);
			}

			if (pos + 1 <= 100000 && !visit[pos + 1]) {
				visit[pos + 1] = 1;
				Q.push(pos + 1);
			}

			if (pos * 2 <= 100000 && !visit[pos * 2]) {
				visit[pos * 2] = 1;
				Q.push(pos * 2);
			}
		}
		ret++;
	}
}


