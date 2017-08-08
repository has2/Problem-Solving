//BOJ
//ID : 4195 / Disjoint Set
//2017/08/01
// char[]로 받아서 string에 할당 가능 while문안에 cin 있을시 무조건 scanf로

#include <cstdio>
#include <cstring>
using namespace std;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int m,n,k,input[52][52];

void dfs(int y,int x) {

	input[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i], tx = x + dx[i];
		if (input[ty][tx]) dfs(ty, tx);
	}
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &m, &n, &k);
		while (k--) {
			int y, x;
			scanf("%d%d", &x, &y);
			input[++y][++x] = 1;
		}

		int cnt = 0;
		for (int y = 1; y <= n; y++)
			for (int x = 1; x <= m; x++) {
				if (input[y][x]) {
					dfs(y, x);
					cnt++;
				}
			}

		printf("%d\n", cnt);
		memset(input, 0, sizeof(input));
	}
}
