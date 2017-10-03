//BOJ
//ID : 5213 // bfs
//2017/10/03

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, map[502][1002],trans[502][1002],track[250000],ret;
bool visit[250000];
struct P {
	int num, ly, lx,ry,rx;
	P(int num, int ly, int lx,int ry,int rx) :num(num),ly(ly), lx(lx),ry(ry),rx(rx){}
};
queue<P> q;

int main() {
	scanf("%d", &n);

	int t=0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) 
			for (int j = 1; j <= 2 * n; j++) {
				if (j % 2 == 1) t++;
				scanf("%d", &map[i][j]);
				trans[i][j] = t;
			}
		
		if (i % 2 == 0) 
			for (int j = 2; j < 2 * n; j++) {
				if (j % 2 == 0) t++;
				scanf("%d", &map[i][j]);
				trans[i][j] = t;
			}
	}
	
	q.push(P(1, 1, 1, 1, 2));
	visit[1] = 1;
	
	bool ok = false;
	int maxnum = 0;
	while (!q.empty()) {
		int qsize = q.size();
		ret++;

		while (qsize--) {
			P here = q.front(); q.pop();
			int hnum = here.num;
			int hly = here.ly, hlx = here.lx;
			int hry = here.ry, hrx = here.rx;

			if (hnum > maxnum) maxnum = hnum;
			if (hnum == n*n - n / 2) {
				ok = true;
				break;
			}

			for (int i = 0; i < 4; i++) {

				int ty = hly + dy[i], tx = hlx + dx[i];
				if (map[hly][hlx] != map[ty][tx] || visit[trans[ty][tx]]) continue;
				if (trans[ty][tx + 1] == trans[ty][tx])
					q.push(P(trans[ty][tx], ty, tx, ty, tx + 1));
				else
					q.push(P(trans[ty][tx], ty, tx - 1, ty, tx));
				visit[trans[ty][tx]] = 1;
				track[trans[ty][tx]] = hnum;
			}

			for (int i = 0; i < 4; i++) {

				int ty = hry + dy[i], tx = hrx + dx[i];
				if (map[hry][hrx] != map[ty][tx] || visit[trans[ty][tx]]) continue;
				if (trans[ty][tx + 1] == trans[ty][tx])
					q.push(P(trans[ty][tx], ty, tx, ty, tx + 1));
				else
					q.push(P(trans[ty][tx], ty, tx - 1, ty, tx));
				visit[trans[ty][tx]] = 1;
				track[trans[ty][tx]] = hnum;
			}
		}
		if (ok) break;
	}

	vector<int> ans;
	for (int i = maxnum; i > 0; i = track[i]) ans.push_back(i);
	printf("%d\n", ans.size());
	for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
}