//BOJ
//ID : 13460 
//2017/09/27

#include <cstdio>
#include <queue>
using namespace std;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, m,rry,rrx,bby,bbx,ret;
char map[10][10];

struct P {
	int ry, rx, by, bx,dir;
	P(int ry,int rx,int by,int bx,int dir):ry(ry),rx(rx),by(by),bx(bx),dir(dir){}
};

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char t;
			scanf(" %c", &t);
			if (t == 'R') {
				rry = i; rrx = j;
				map[i][j] = '.';
			}
			else if (t == 'B') {
				bby = i; bbx = j;
				map[i][j] = '.';
			}
			else map[i][j] = t;
		}
	
	queue<P> q;
	for (int i = 0; i < 4; i++)
		q.push(P(rry, rrx, bby, bbx, i));

	while (1) {

		int qsize = q.size();
		ret++;
		while (qsize--) {

			P here = q.front(); q.pop();
			int hry = here.ry, hrx = here.rx, hby = here.by, hbx = here.bx, hdir = here.dir;

			int ty[2], tx[2];
			int red;
			if (hdir < 2) {
				if (hry*dy[hdir] > hby*dy[hdir]) {
					ty[0] = hry; tx[0] = hrx;
					ty[1] = hby; tx[1] = hbx;
					red = 0;
				}
				else {
					ty[0] = hby; tx[0] = hbx;
					ty[1] = hry; tx[1] = hrx;
					red = 1;
				}
			}
			else {
				if (hrx*dx[hdir] > hbx*dx[hdir]) {
					ty[0] = hry; tx[0] = hrx;
					ty[1] = hby; tx[1] = hbx;
					red = 0;
				}
				else {
					ty[0] = hby; tx[0] = hbx;
					ty[1] = hry; tx[1] = hrx;
					red = 1;
				}
			}

			bool ck = true;
			bool isGoal = false;
			int i;
			for (i = 0; i < 2; i++) {

				int cy = ty[i], cx = tx[i];
				while (1) {
					cy += dy[hdir], cx += dx[hdir];
					if (!isGoal && (cy == ty[1-i] && cx == tx[1-i]) || map[cy][cx] == '#') {

						ty[i] = cy - dy[hdir];
						tx[i] = cx - dx[hdir];
						break;
					}

					if (map[cy][cx] == 'O') {
						if (i == red) {
							isGoal = true;
							break;
						}
						else {
							ck = false;
							break;
						}
					}
				}
				if (!ck) break;
			}
			if (isGoal && ck) {
				printf("%d", ret);
				return 0;
			}

			if (!ck) continue;

			
			hry = ty[red], hrx = tx[red];
			hby = ty[1-red], hbx = tx[1-red];

			if (hdir < 2) {
				q.push(P(hry, hrx, hby, hbx, 2));
				q.push(P(hry, hrx, hby, hbx, 3));
			}
			else {
				q.push(P(hry, hrx, hby, hbx, 0));
				q.push(P(hry, hrx, hby, hbx, 1));
			}
		}
		if (q.size() == 0 || ret == 10) {
			puts("-1");
			return 0;
		}
	}
}