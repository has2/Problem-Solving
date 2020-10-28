#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
struct P {
	int y, x;
};

int R, C;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
char p[7] = {'|','-','1','2','3','4','+'};
char map[25][25];
vector<int> rule[300];
bool visit[25][25];
P s, e;
int oppo(int a) {
	if (a % 2==0) a++;
	else a--;
	return a;
}
bool check(int y, int x) {
	return y < 0 || x < 0 || y >= R || x >= C;
}
bool ispipe(int y, int x) {
	char c = map[y][x];
	return c == '|' || c == '-' || c == '+' || ('1' <= c && c <= '4');
}
void dfs(int y, int x,P& a) {
	visit[y][x] = 1;
	char pipe = map[y][x];
	for (auto d : rule[pipe]) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (check(ny, nx) || visit[ny][nx] || map[ny][nx] == 'Z' || map[ny][nx] == 'M') continue;
		if (map[ny][nx] == '.') a = { ny,nx };
		else dfs(ny, nx, a);
	}
}

int main() {

	rule['|'] = { 0,1 };
	rule['-'] = { 2,3 };
	rule['+'] = { 0,1,2,3 };
	rule['1'] = { 1,3 };
	rule['2'] = { 0,3 };
	rule['3'] = { 0,2 };
	rule['4'] = { 2,1 };

	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'M') s = { i,j };
			if (map[i][j] == 'Z') e = { i,j };
		}
	}
	for (int i = 0; i < 4; i++) {
		int ny = s.y + dy[i];
		int nx = s.x + dx[i];
		if (!check(ny, nx) && ispipe(ny,nx)) {
			s = { ny,nx };
			visit[s.y][s.x] = 1;
			break;
		}
		ny = e.y + dy[i];
		nx = e.x + dx[i];
		if (!check(ny, nx) && ispipe(ny, nx)) {
			visit[e.y][e.x] = 1;
			e = s;
			s = { ny,nx };
			break;
		}
	}
	P sp = { -1,-1 };
	dfs(s.y, s.x, sp);

	set<int> need;
	for (int i = 0; i < 4; i++) {
		int fy = sp.y + dy[i];
		int fx = sp.x + dx[i];
		if (check(fy, fx) || map[fy][fx] == '.' || map[fy][fx] == 'Z' || map[fy][fx] == 'M') continue;

		for (int d : rule[map[fy][fx]]) {
			if (check(fy + dy[d], fx + dx[d])) continue;
			if (fy + dy[d] == sp.y && fx + dx[d] == sp.x) need.insert(oppo(d));
		}
	}

	for (int i = 0; i < 7; i++) {
		bool ok = 1;
		if (rule[p[i]].size() == need.size()) {
			for (int d : rule[p[i]]) {
				if (need.find(d) == need.end()) {
					ok = 0;
				}
			}
			if (ok) {
				printf("%d %d %c", sp.y + 1, sp.x + 1, p[i]);
				return 0;
			}
		}
	}
}