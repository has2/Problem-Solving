#include <cstdio>
#include <climits>
int t;
typedef long long ll;
ll a, b;
bool check(ll x) {
	return b <= a*x;
}
ll bs() {
	ll lo = 0;
	ll hi = INT_MAX;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		bool c = check(mid);
		if (c) hi = mid;
		else lo = mid;
	}
	return hi;
}

ll gcd(ll u, ll v) {
	while (u%v) {
		ll t = v;
		v = u%v;
		u = t;
	}
	return v;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &a, &b);
		while (1) {
			if (a == 1) {
				printf("%lld\n", b);
				break;
			}
			ll v = bs();
			a = v*a - b;
			b = v*b;

			ll g = gcd(b, a);
			a /= g;
			b /= g;
		}
	}
}