#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll N, k;
int Q;
ll getH(ll a) {
	ll h = 0;
	while (a) {
		if (a%k == 0) a--;
		h++;
		a /= k;
	}
	return h;
}
ll getPar(ll a) {
	if (a <= k) return 0;
	ll r = a%k;
	if (r==0) a--;
	return a / k;
}
int main() {
	scanf("%lld%lld%d", &N,&k,&Q);
	while (Q--) {
		ll a, b,diff=0;
		scanf("%lld%lld", &a, &b);
		a--, b--;
		if (a > b) swap(a, b);
		if (k == 1) {
			printf("%lld\n", b - a);
			continue;
		}

		ll ah = getH(a), bh = getH(b);
		diff += bh - ah;

		while (getH(b) != ah) b = getPar(b);
		
		ll cnt = 0;
		while (b != a) {
			cnt++;
			a = getPar(a);
			b = getPar(b);
		}
		printf("%lld\n", diff + 2 * cnt);
	}
}