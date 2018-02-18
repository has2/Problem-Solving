//BOJ
//ID : 3190 // simulation
//2017/10/17

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, k, l, map[101][101],cd;

int rL(int d) {
	return d < 2 ? d + 2 : 3 - d;
}
int rR(int d) {
	return d < 2 ? 3 - d : d - 2;
}
struct P { int y,x; };
int main() {
	scanf("%d%d", &n,&k);
	while (k--) {
		int y, x;
		scanf("%d%d", &y, &x);
		map[y][x] = 1;
	}
	
	vector<P> snake;
	snake.push_back({ 1,1 });
	map[1][1] = 2;
	cd = 2;
	scanf("%d", &l);

	int tidx = 0;
	int time = 0;
	int sec;
	char dir;
	while (1) {

		if (l>0) scanf("%d %c", &sec, &dir);
		l--;
		for (int i = time+1; i <= sec; i++) {
			P here = snake.back();

			int ny = here.y+dy[cd];
			int nx = here.x+dx[cd];
			if (ny < 1 || nx < 1 || ny > n || nx > n || map[ny][nx] == 2) {
				printf("%d", i);
				return 0;
			}
			snake.push_back({ ny,nx });
			if (map[ny][nx] == 0) {
				P tail = snake[tidx++];
				map[tail.y][tail.x] = 0;
			}
			map[ny][nx] = 2;
		}
		time = sec;
		if (dir == 'D') cd = rR(cd);
		else cd = rL(cd);
		if (l == 0) sec = 10000000;
	}
}

