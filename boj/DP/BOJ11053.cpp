//BOJ
//ID : 11053 / DP
//2017/08/05

#include <cstdio>
#include <cstring>
#include <algorithm>

int n, a[1001],cache[1001];

int sol(int m) {

	if (m == n) return 1;

	int& ret = cache[m];

	if (ret != -1) return ret;

	ret = 1;
	for (int i = m + 1; i <= n; i++) 
		if (a[m] < a[i])
			ret = std::max(ret, sol(i)+1);
	
	return ret;
}

int main() {

	memset(cache, -1, sizeof(cache));
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	printf("%d", sol(0)-1);
}