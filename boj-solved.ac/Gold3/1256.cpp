#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
ll dp[201][201];

ll getCom(int a, int b) {

	if (a == b) return 1;
	if (b == 0) return 1;
	ll& ret = dp[a][b];
	if (ret != -1) return ret;

	ret = getCom(a-1, b) + getCom(a - 1, b - 1);
	return ret;
}

int main() {
	ll n, m, k;
	scanf("%llu%llu%llu", &n, &m, &k);
	memset(dp, -1, sizeof(dp));
	if (getCom(n+m,m) < k) {
		puts("-1");
		return 0;
	}

	int total = n + m;
	string ret = "";
	for (int i = 0; i < total; i++) {
		if (n > 0 && getCom(n + m - 1, m) >= k) {
			ret += 'a';
			n--;
		}
		else {
			ret += 'z';
			k -= getCom(n + m - 1, m);
			m--;
		}
	}
	cout << ret;
}