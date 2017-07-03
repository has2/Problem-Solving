#include <cstdio>
#include <algorithm>

typedef long long ll;
const ll MAX = 90000000;
ll arr[500000];

int main(void) {

	int N, M;
	ll num,l,r,m;
	scanf("%d", &N);
	arr[0] = -MAX; arr[N + 1] = MAX;

	for (int i = 1; i <= N; i++)
		scanf("%lld", &arr[i]);
	std::sort(arr, arr + N+2);

	scanf("%d", &M);
	while (M--) {
		scanf("%lld", &num);
		ll lidx, ridx;
		l = 0, r = N+1;	
		while (l + 1 != r) {
			m = (l + r) / 2;
			if (arr[m] < num) l = m;
			else r = m;
		}
		lidx = l;
		
		l = 0, r = N +1;
		while (l + 1 != r) {
			m = (l + r) / 2;
			if (arr[m] > num) r = m;
			else l = m;
		}
		ridx = r;
		printf("%lld ", ridx - lidx - 1);
	}
}