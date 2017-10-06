//BOJ
//ID : 7569 // bfs
//2017/10/06

#include <cstdio>
#include <queue>
using namespace std;
struct P {
	int y, x, z;
	P(int y,int x,int z):y(y),x(x),z(z){}
};
int dy[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int m,n,h,box[100][100][100],tm,day=0;
queue<P> q;
int main() {
	scanf("%d%d%d", &m, &n, &h);
	for (int z = 0; z < h; z++)
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++) {
				scanf("%d", &box[y][x][z]);
				if (!box[y][x][z]) tm++;
				else if (box[y][x][z] == 1)  q.push(P(y, x, z));
			}

	if (tm == 0) {
		puts("0");
		return 0;
	}

	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {

			P here = q.front(); q.pop();
			int hy = here.y, hx = here.x, hz = here.z;

			for (int i = 0; i < 6; i++) {
				int ty = hy + dy[i], tx = hx + dx[i], tz = hz + dz[i];
				if (ty < 0 || tx < 0 || tz < 0 || ty >= n || tx >= m || tz >= h || box[ty][tx][tz] != 0) continue;
				tm--;
				q.push(P(ty, tx, tz));
				box[ty][tx][tz] = 1;
			}
		}
		day++;
		if (tm == 0) {
			printf("%d", day);
			return 0;
		}
	}
	puts("-1");
}