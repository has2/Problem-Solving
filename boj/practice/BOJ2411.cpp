//BOJ
//ID : 2411 // dp
//2017/09/27

#include <cstdio>
#include <cstring>
using namespace std;
int n, m, a, b,c,d;
int map[100][100], cache[100][100][201];

int sol(int y, int x, int k) {


	if (y == n - 1 && x == m - 1) return k == a;
	
	int& ret = cache[y][x][k];
	if (ret != -1) return ret;
	ret = 0;
	
	if (y + 1 >= 0 && x >= 0 && y + 1 < n && x < m && map[y + 1][x] != 2) 
		ret += sol(y + 1, x, k + map[y + 1][x]);
	
	if (y >= 0 && x + 1>= 0 && y < n && x+1 < m && map[y][x+1] != 2)
		ret += sol(y, x+1, k + map[y][x+1]);

	return ret;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 0; i < a; i++) {
		scanf("%d%d", &c, &d);
		map[c - 1][d - 1] = 1;
	}
	while (b--) {
		scanf("%d%d", &c, &d);
		map[c - 1][d - 1] = 2;
	}
	memset(cache, -1, sizeof(cache));
	if (a > 199) puts("0");
	else printf("%d",sol(0, 0, 0));
}