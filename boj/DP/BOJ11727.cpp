//BOJ
//ID : 11727 // dp
//2017/09/30
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 10007;
int n,cache[1000];

int sol(int cur) {
	
	if (n == cur) return 1;
	if (n < cur) return 0;

	int& ret = cache[cur];
	if (ret != -1) return ret;

	return ret = (sol(cur + 1) + 2*sol(cur + 2))%MOD;
	
}

int main() {
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	printf("%d", sol(0));
}