//BOJ
//ID : 14888 // dfs
//2017/10/25

#include <cstdio>
#include <algorithm>
using namespace std;
int n,arr[11],oper[4],INF=1000000000,minv,maxv;

void dfs(int cur, int a, int b, int c, int d,int val) {

	if (cur == n && a == 0 && b == 0 && c == 0 && d == 0) {
		minv = min(minv, val);
		maxv = max(maxv, val);
	}

	if (a > 0) dfs(cur + 1, a - 1, b, c, d, val + arr[cur]);
	if (b > 0) dfs(cur + 1, a, b-1, c, d, val - arr[cur]);
	if (c > 0) dfs(cur + 1, a, b, c-1, d, val * arr[cur]);
	if (d > 0) dfs(cur + 1, a, b, c, d-1, val / arr[cur]);

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &oper[i]);
	minv =INF;
	maxv = -INF;
	dfs(1, oper[0], oper[1], oper[2], oper[3], arr[0]);
	printf("%d\n%d", maxv, minv);
}