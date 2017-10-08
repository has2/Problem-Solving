//SW Expert
//ID : 2112 // brute force
//2017/10/08

#include <cstdio>
#include <vector>
using namespace std;
int d, w, th;
bool film[13][20],isok;

bool check() {

	for (int j = 0; j < w; j++) {
		int maxv = 0;

		for (int i = 0; i < d; i++) {
			int cnt = 0;
			for (int k = i; k < d; k++) {

				if (film[i][j] == film[k][j]) cnt++;
				else {
					i = k-1;
					break;
				}
				if (cnt > maxv) maxv = cnt;
			}
		}

		if (maxv < th) return false;
	}
	return true;
}

void sol(int cur, int cnt,int mcnt) {

	if (isok) return;

	if (cnt >= mcnt) {
		if (check()) {
			isok = true;
		}
		return;
	}
	if (cur > d) return;

	vector<int> tmp(w);
	for (int i = 0; i < w; i++) tmp[i] = film[cur][i];
	sol(cur + 1, cnt,mcnt);

	for (int i = 0; i < w; i++) film[cur][i] = 0;
	sol(cur + 1, cnt + 1,mcnt);
	
	for (int i = 0; i < w; i++) film[cur][i] = 1;
	sol(cur + 1, cnt + 1,mcnt);
	
	for (int i = 0; i < w; i++) film[cur][i] = tmp[i];
}


int main() {
	
	int c;
	scanf("%d", &c);
	for (int tc = 1; tc <= c; tc++) {
		scanf("%d%d%d", &d, &w, &th);
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++) scanf("%d", &film[i][j]);

		int res;
		for (int i = 0; i <= d; i++) {
			isok = false;
			sol(0, 0, i);
			if (isok) {
				res = i;
				break;
			}
		}
		printf("#%d %d\n",tc,res);
	}
}