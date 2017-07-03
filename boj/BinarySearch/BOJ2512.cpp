#include <cstdio>
#include <algorithm>
long long m[10001];

int main(void) {

	int N;
	long long M, l=0, r = -1, mid, sum=0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &m[i]);
		r = std::max(r, m[i]);
		sum += m[i];
	}
	scanf("%lld", &M);
	if (sum <= M) {
		printf("%lld", r);
		return 0;
	}

	while (l+1 != r) {
		sum = 0;
		mid = (l + r) / 2;
		for (int i = 1; i <= N; i++) 
			sum += mid >= m[i] ? m[i] : mid;
		
		if (sum <= M) l = mid;
		else r = mid;
	}
	printf("%lld", l);
}