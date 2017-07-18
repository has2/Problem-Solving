#include <cstdio>
const long long MAX = 2000000000;
long long N, M;
int target;

int diff(long long add) {
	int newprob = ((M + add)*100) / (N + add);
	return target - newprob;
}

int main() {
	int c;
	scanf("%d", &c);
	while(c--){
		scanf("%lld%lld", &N, &M);
		target = (M*100)/N + 1;

		if (target == 101) {
			printf("-1\n");
			continue;
		}

		long long lo = 0,hi = MAX+1;
		while (lo + 1 < hi) {
			long long mid = (lo + hi) / 2;
			int dif = diff(mid);
			if (dif <= 0) hi = mid;
			else lo = mid;
		}
		
		if(hi == MAX+1 || diff(hi) > 0){
			printf("-1\n");
			continue;
		}
		printf("%lld\n", hi);
	}
}