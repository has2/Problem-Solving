//BOJ
//ID : 13302 // dp
//2017/10/06

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int cost[3] = { 10000,25000,37000 },INF=987654321;
int n,m,t, cache[42][101];
bool a[101];
int sol(int cp, int cur) {

	if (cur > n) return 0;
	int& ret = cache[cp][cur];
	if (ret != -1) return ret;

	if (a[cur]) return ret = sol(cp, cur + 1);

	ret = INF;
	for (int i = 0; i < 3; i++)
		ret = min(ret, cost[i] + sol(cp + i, cur + 2 * i + 1));
	if (cp > 2) ret = min(ret, sol(cp - 3, cur + 1));
	
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d", &t);
		a[t] = 1;
	}
	memset(cache, -1, sizeof(cache));
	printf("%d", sol(0, 1));
}