//BOJ
//ID : 12100 // brute force
//2017/10/16

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n, map[20][20],ret;

void rea(vector<int>& v) {

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) continue;

		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] == 0) continue;
			if (v[i] == v[j]) {
				v[i] *= 2;
				v[j] = 0;
			}
			break;
		}
		for (int k = 0; k < i; k++) {
			if (v[k] == 0) {
				v[k] = v[i];
				v[i] = 0;
				break;
			}
		}
	}
}

void recover(int tmap[20][20]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) map[i][j] = tmap[i][j];
}

void sol(int d,int dep) {

	if (dep == 5) {
		int maxv = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				maxv = max(maxv, map[i][j]);
		ret = max(ret, maxv);
		return;
	}

	int tmap[20][20] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) tmap[i][j] = map[i][j];

	vector<int> tmp(n);

	if (d != 0) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) tmp[y] = map[y][x];
			rea(tmp);
			for (int y = 0; y < n; y++) map[y][x] = tmp[y];
		}
		sol(0, dep + 1);
		recover(tmap);
	}

	if (d != 1) {
		for (int x = 0; x < n; x++) {
			for (int y = n-1; y >= 0; y--) tmp[n-1-y] = map[y][x];			
			rea(tmp);
			for (int y = n - 1; y >= 0; y--) map[y][x] = tmp[n-1-y];
		}
		sol(1, dep + 1);
		recover(tmap);

	}

	if (d != 2) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) tmp[x] = map[y][x];
			rea(tmp);
			for (int x = 0; x < n; x++) map[y][x] = tmp[x];
		}
		sol(2, dep + 1);
		recover(tmap);

	}

	if (d != 3) {
		for (int y = 0; y < n; y++) {
			for (int x = n-1; x >= 0; x--) tmp[n-1-x] = map[y][x];
			rea(tmp);
			for (int x = n-1; x >= 0; x--) map[y][x] = tmp[n-1-x];
		}
		sol(3, dep + 1);
		recover(tmap);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);

	sol(-1, 0);
	printf("%d", ret);
}