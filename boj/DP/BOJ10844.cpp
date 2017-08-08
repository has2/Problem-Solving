//BOJ
//ID : 10844 / DP
//2017/07/27

#include <cstdio>
int MOD = 1000000000;
int n,cache[101][10],t;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 9; i++)
		cache[1][i]=1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j + 1 < 10) cache[i][j] = (cache[i][j] + cache[i - 1][j + 1])%MOD;
			if (j - 1 >= 0) cache[i][j] = (cache[i][j] + cache[i - 1][j - 1])%MOD;
		}
	}
	for (int i = 0; i <= 9; i++)
		t =(t+cache[n][i])%MOD;
	printf("%d", t);
}

