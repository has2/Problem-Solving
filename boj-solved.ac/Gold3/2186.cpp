#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n, m,k;
int dp[100][100][81], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };
string map[100],t;

int sol(int y, int x, int idx) {
	if (idx == (int)t.size()) return 1;

	int& ret = dp[y][x][idx];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int ny = y + dy[i] * j;
			int nx = x + dx[i] * j;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(map[ny][nx] == t[idx]) ret += sol(ny, nx, idx + 1);
		}
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) cin >> map[i];
	cin >> t;
	memset(dp, -1, sizeof(dp));
	
	int ans = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (map[i][j] == t[0]) ans += sol(i, j, 1);
	printf("%d", ans);
}