//BOJ
//ID : 3055 // bfs
//2017/09/30
#include <cstdio>
#include <queue>
using namespace std;
int n, m,map[50][50],ret,ey,ex;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

struct P {
	int y, x;
	P(int y,int x):y(y),x(x){}
};

int main() {

	queue<P> dochi,water;
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			char ch = getchar();
			map[i][j] = ch;
			if (ch == 'S') dochi.push(P(i, j));
			else if(ch == '*') water.push(P(i, j));
			else if (ch == 'D') {
				map[i][j] = '.';
				ey = i; ex = j;
			}
		}
	}

	while (!dochi.empty()) {

		int wsize = water.size();
		int dsize = dochi.size();
		
		while (wsize--) {

			int hy = water.front().y; 
			int hx = water.front().x;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (ty < 0 || tx < 0 || ty >= n || tx >= m || map[ty][tx] != '.' || (ty == ey && tx == ex) ) continue;
				water.push(P(ty, tx)); map[ty][tx] = '*';
			}
		}

		while (dsize--) {

			int hy = dochi.front().y;
			int hx = dochi.front().x;
			dochi.pop();
			
			if (hy == ey && hx == ex) {
				printf("%d", ret);
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int ty = hy + dy[i], tx = hx + dx[i];
				if (ty < 0 || tx < 0 || ty >= n || tx >= m || map[ty][tx] != '.') continue;
				dochi.push(P(ty, tx)); map[ty][tx] = 'S';
			}
		}
		ret++;
	}
	puts("KAKTUS");
}