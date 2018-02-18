//BOJ
//ID : 14890 // simulation
//2017/10/25

#include <cstdio>
#include <vector>
using namespace std;
int n, l, map[100][100];

bool f(vector<int>& tmp) {

	bool ck[100] = { 0 };

	for (int j = 0; j < n; j++) {

		if (j == n - 1) return 1;
		
		int diff = tmp[j] - tmp[j+1];
		if (diff>1 || diff < -1) break;
		if (diff == -1) {
			bool ok = true;
			for (int k = j; k > j - l; k--) {
				if (k < 0 || tmp[k] != tmp[j] || ck[k]) {
					ok = false;
					break;
				}
			}
			if (!ok) break;
			for (int k = j; k > j - l; k--) ck[k] = 1;
		}
		else if (diff == 1) {
			bool ok = true;
			for (int k = j + 1; k <= j + l; k++) {
				if (k >= n || tmp[k] != tmp[j + 1] || ck[k]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				for (int k = j+1; k <= j + l; k++) ck[k] = 1;
				j = j + l-1;
			}
			else break;
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &n,&l);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);

	int total=0;
	vector<int> tmp(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) tmp[j] = map[i][j];
		total += f(tmp);
		for (int j = 0; j < n; j++) tmp[j] = map[j][i];
		total += f(tmp);
	}
	printf("%d", total);
}