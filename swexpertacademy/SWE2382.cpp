//SW Expert
//ID : 2382 // bfs
//2017/10/08

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };
struct P {
	int y, x, c, d;
	P() { y = 0, x = 0, c = 0, d = 0; }
	P(int y,int x,int c,int d):y(y),x(x),c(c),d(d){}
};
int n, m, k,tc;

int main() {
	scanf("%d", &tc);
	for (int test = 1; test <= tc; test++) {
		scanf("%d%d%d", &n, &m, &k);
		queue<P> q;
		while (k--) {
			int y, x, c, d;
			scanf("%d%d%d%d", &y, &x, &c, &d);
			q.push(P(y, x, c, d));
		}
		int time = 0, res = 0;
		vector<pair<int, int> > map[100][100];

		bool ok = false;
		while (!q.empty()) {

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					map[i][j].clear();


			int qsize = q.size();
			while (qsize--) {
				P h = q.front(); q.pop();
				int hy = h.y, hx = h.x, hc = h.c, hd = h.d;
				int ty = hy + dy[hd], tx = hx + dx[hd];
				if (ty == 0 || tx == 0 || ty == n - 1 || tx == n - 1) {
					hc /= 2;
					if (hd < 3) hd = 3 - hd;
					else hd = 7 - hd;
				}
				map[ty][tx].push_back(make_pair(hc, hd));
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j].size() == 1) q.push(P(i, j, map[i][j][0].first, map[i][j][0].second));
					else if (map[i][j].size() > 1) {

						int nd, tt = 0;
						int mm = 0;
						for (int k = 0; k < map[i][j].size(); k++) {
							if (map[i][j][k].first > mm) {
								mm = map[i][j][k].first;
								nd = map[i][j][k].second;
							}
							tt += map[i][j][k].first;
						}
						q.push(P(i, j, tt, nd));
					}
				}
			}
			if (++time == m) {
				while (!q.empty()) {
					res += q.front().c;
					q.pop();
				}
				ok = true;
				break;
			}
			if (ok) break;
		}
		printf("#%d %d\n",test,res);
	}
}