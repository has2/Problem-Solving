//BOJ
//ID : 1987 // backtracking
//2017/09/17

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int map[20][20];
bool selected[26], visited[20][20];
int R, C,ret;

void sol(int y, int x, int cnt) {
	
	ret = max(cnt, ret);

	visited[y][x] = 1;
	selected[map[y][x]] = 1;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || tx < 0 || ty >= R || tx >= C || visited[ty][tx]) continue;
		if(!selected[map[ty][tx]])
			sol(ty, tx, cnt + 1);
	}
	visited[y][x] = 0;
	selected[map[y][x]] = 0;
}

int main() {
	scanf("%d%d", &R, &C);
	string tmp;
	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++)
			map[i][j] = tmp[j]-'A';
	}
	sol(0, 0, 1);
	printf("%d", ret);
}