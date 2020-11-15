#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int ans = 0;
bool check(int ny, int nx) {
	return ny < 0 || nx < 0 || ny >= 4 || nx >= 4;
}
P eat(int sy, int sx, int fy, int fx, vector < vector<P>>& m, vector<P>& fish) {
	int fnum = m[fy][fx].first;
	int fdir = m[fy][fx].second;
	m[sy][sx] = { -1,0 };
	m[fy][fx] = { -2,0 };
	fish[fnum] = { -1,0 };
	return { fnum,fdir };
}
void sol(vector < vector<P>> m,vector<P> fish,int y,int x,int dir,int point) {
	ans = max(ans, point);
	for (int i = 1; i <= 16; i++) {
		
		if (fish[i].first == -1) continue;
		int fy = fish[i].first, fx = fish[i].second,fd = m[fy][fx].second,ny = fy+dy[fd],nx = fx+dx[fd];

		while (check(ny, nx) || m[ny][nx].first == -2) {
			fd = (fd+1) % 8;
			ny = fy + dy[fd];
			nx = fx + dx[fd];
		}
		swap(m[ny][nx], m[fy][fx]);
		m[ny][nx].second = fd;
		if (m[ny][nx].first > 0) fish[m[ny][nx].first] = { ny,nx };
		if (m[fy][fx].first > 0) fish[m[fy][fx].first] = { fy,fx };
	}

	int sy = y,sx = x;
	while (1) {
		sy += dy[dir];
		sx += dx[dir];
		if (check(sy, sx)) break;
		if (m[sy][sx].first > 0) {
			auto cpm = m;
			auto cpf = fish;
			P e = eat(y, x, sy, sx, cpm, cpf);
			sol(cpm, cpf, sy, sx, e.second, point + e.first);
		}
	}
}

int main() {
	vector < vector<P>> m(4, vector<P>(4));
	vector<P> fish(17);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			scanf("%d%d", &a, &b);
			m[i][j] = { a,b - 1 };
			fish[a] = { i,j };
		}
	}
	P e = eat(0, 0, 0, 0, m, fish);
	sol(m, fish, 0, 0, e.second, e.first);
	printf("%d", ans);
}