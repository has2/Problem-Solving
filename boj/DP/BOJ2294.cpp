//BOJ
//ID : 2294 // dp
//2017/09/30
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n, a[100], k,cache[10001];

int sol(int m) {
	
	if (m == 0) return 0;

	int& ret = cache[m];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < n; i++) 
		if (m - a[i] >= 0) ret = min(ret, 1 + sol(m - a[i]));
	
	return ret;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	memset(cache, -1, sizeof(cache));

	int res = sol(k);
	if (res == INF) puts("-1");
	else printf("%d", res);
}