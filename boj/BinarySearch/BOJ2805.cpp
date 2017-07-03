#include <cstdio>

typedef long long ll;
const ll maxH = 1000000000;

ll tree[10000001];

int main(void) {

	int N;
	ll M, l = 1, r = maxH, mid;
	scanf("%d%lld", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &tree[i]);

	while (l <= r) {
	    mid = (l + r) / 2;
		if (mid == l) break;
		ll heightSum = 0;
		for (int i = 1; i <= N; i++)
			heightSum += tree[i] > mid ? tree[i] - mid : 0;

		if (heightSum >= M) l = mid;
		else if (heightSum < M) r = mid;
	}
	printf("%lld\n", mid);
}