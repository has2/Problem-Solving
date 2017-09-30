//BOJ
//ID : 11057 // dp
//2017/09/30
#include <cstdio>
#include <cstring>
int MOD = 10007;
int n,cache[10][1001];

int sol(int k, int cur) {
	
	if (cur == 1) return 1;

	int& ret = cache[k][cur];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 10; i++) 
		if (k <= i) ret = (ret+sol(i, cur-1))%MOD;
	
	return ret;
}

int main() {
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	printf("%d", sol(0, n + 1));;
}