//SW Expert
//ID : 2105 // backtracking
//2017/10/09

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int dy[4] = { -1,1,1,-1 };
int dx[4] = { 1,1,-1,-1 };
int n,map[20][20],tmax,dcnt;
bool range(int y, int x) {
	return (y >= 0 && x >= 0 && y < n && x < n);
}

void sol(int y, int x,int a,int b,int d,vector<int> desert) {

	if (a == 0) {
		int ty = y + dy[d], tx = x + dx[d];

		if (range(ty, tx) && !desert[map[ty][tx]]) {
			desert[map[ty][tx]] = 1;
			sol(ty, tx, a + 1, b, d,desert);
		}
		return;
	}
		
	if (d == 0) {

		sol(y, x, a, b, d + 1, desert);

		int ty = y + dy[d], tx = x + dx[d];
		if (range(ty, tx) && !desert[map[ty][tx]]) {
			desert[map[ty][tx]] = 1;
			sol(ty, tx, a + 1, b, d, desert);
		}
	}
	else if (d == 1) {

		sol(y, x, a, b, d + 1, desert);
		int ty = y + dy[d], tx = x + dx[d];
		if (range(ty, tx) && !desert[map[ty][tx]]) {
			desert[map[ty][tx]] = 1;
			sol(ty, tx, a, b+1, d, desert);
		}
	}

	else if (d == 2) {
		int ty, tx;
		for (int i= 1; i <= a; i++) {
			ty = y + i*dy[d], tx = x + i*dx[d];
			if (!range(ty,tx) || desert[map[ty][tx]]) return;
			desert[map[ty][tx]] = 1;
		}
		d++;
		int hy, hx;
		for (int i= 1; i < b; i++) {
			hy = ty+i*dy[d], hx = tx+i*dx[d];
			if (!range(hy, hx) || desert[map[hy][hx]]) return;
			desert[map[hy][hx]] = 1;
		}
		tmax = max(tmax, 2*(a+b));
	}
}

int main() {

	int tc; scanf("%d", &tc);
	for (int test = 1; test <= tc; test++) {

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);

		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmax = 0;
				vector<int> tmp(101,0);
				tmp[map[i][j]] = 1;
				sol(i, j, 0, 0, 0, tmp);
				res = max(res, tmax);
			}
		}
		if (res == 0) res = -1;
		printf("#%d %d\n",test,res);
	}
}