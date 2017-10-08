//SW Expert
//ID : 2117 // bfs
//2017/10/08

#include <cstdio>
#include <queue>
using namespace std;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;
bool map[20][20]; 

struct P {
	int y, x;
	P(int y,int x):y(y),x(x){}
};

int bfs(int y, int x) {

	int k = 0,maxhome = 0,sum = 0,hcnt = 0;
	bool visit[20][20] = { 0 };
	queue<P> q;
	q.push(P(y, x));
	visit[y][x] = 1;

	while (!q.empty()) {
		
		int qsize = q.size();

		while (qsize--) {

			int hy = q.front().y;
			int hx = q.front().x; q.pop();
			if (map[hy][hx]) {
				sum += m;
				hcnt++;
			}
			
			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (ty < 0 || tx < 0 || ty >= n || tx >= n || visit[ty][tx]) continue;
				q.push(P(ty, tx));
				visit[ty][tx] = 1;
			}
		}
		k++;
		if (sum - k*k - (k - 1)*(k - 1) >= 0 && hcnt > maxhome) maxhome = hcnt;
	}
	return maxhome;
}

int main() {

	int c;
	scanf("%d", &c);
	for (int tc = 1; tc <= c; tc++) {

		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		int ret = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ret = max(ret, bfs(i, j));

		printf("#%d %d\n",tc,ret);
	}
}