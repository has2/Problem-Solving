//BOJ
//ID : 2580 // backtracking
//2017/09/20

#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> p;
int map[9][9];

bool check(int y, int x) {

	for (int i = 0; i < 9; i++) {
		if (i != x && map[y][x] == map[y][i]) return false;
		if (i != y && map[y][x] == map[i][x]) return false;
	}

	int ty = y - y % 3, tx = x - x % 3;
	for (int i = ty; i < ty + 3; i++) {
		for (int j = tx; j < tx + 3; j++) {
			if (i == y && j == x) continue;
			if (map[y][x] == map[i][j]) return false;
		}
	}
	return true;
}

void sol(int cur) {

	if (cur == p.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
		return;
	}

	int y = p[cur].first, x = p[cur].second;

	for (int i = 1; i <= 9; i++) {
		map[y][x] = i;
		if (!check(y, x)) continue;
		sol(cur + 1);
	}
	map[y][x] = 0;
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (!map[i][j]) 
				p.push_back(make_pair(i, j));
		}
	}
	sol(0);
}