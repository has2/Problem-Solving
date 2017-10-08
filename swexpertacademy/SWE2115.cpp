//SW Expert
//ID : 2115 // brute force
//2017/10/08

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, c, a[11][11], temp, ret;
vector<int> ans;
vector<int> rv1, rv2;
void sol(int y, int x, int cur, int v, int mcost, vector<int> tv) {
	if (cur == m) {
		if (v <= c && temp < mcost) {
			temp = mcost;
			ans = tv;
		}
		return;
	}
	vector<int> nv = tv;
	nv.push_back(a[y][x + cur]);
	sol(y, x, cur + 1, v + a[y][x + cur], mcost + a[y][x + cur] * a[y][x + cur], nv);
	sol(y, x, cur + 1, v, mcost, tv);

}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int testcase = 1; testcase <= tc; testcase++) {
		ret = 0;
		scanf("%d%d%d", &n, &m, &c);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - m + 1; j++) {
				temp = 0;
				vector<int> tv;
				sol(i, j, 0, 0, 0, tv);
				int v1 = temp;
				vector<int> v1v = ans;

				int v2;
				vector<int> v2v;
				temp = 0;
				for (int k = j + m; k <= n - m + 1; k++) {
					if (k + m - 1 > n) break;
					tv.clear();
					sol(i, k, 0, 0, 0, tv);
					v2 = temp;
					v2v = ans;
					if (ret < v2 + v1) {
						ret = v1 + v2;
						rv1 = v1v;
						rv2 = v2v;
					}
				}

				for (int k = i + 1; k <= n; k++) {
					for (int l = 1; l <= n - m + 1; l++) {
						tv.clear();

						sol(k, l, 0, 0, 0, tv);
						v2 = temp;
						v2v = ans;
						if (ret < v2 + v1) {
							ret = v2 + v1;
							rv1 = v1v;
							rv2 = v2v;
						}
					}
				}
			}
		}
		printf("#%d %d\n", testcase, ret);
	}
}