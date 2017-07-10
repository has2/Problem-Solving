#include <cstdio>
#include <cstring>
#include <algorithm>
int seq[100001],cache[100001];

int sol(int n) {

	if (n == 0) return 0;

	int& ret = cache[n];
	
	if (ret != -1) return ret;
	
	int bf = sol(n - 1);
	return cache[n] = bf < 0 ? seq[n] : bf+seq[n];
}


int main(void) {

	memset(cache, -1, sizeof(cache));
	int N,sum;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &seq[i]);

	sum = sol(N);
	for (int i = 1; i < N; i++)
		sum = std::max(sum, cache[i]);
	printf("%d\n", sum);
}
