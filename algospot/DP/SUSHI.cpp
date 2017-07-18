#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int price[20], pref[20], cache[201];
const int MOD = 201;
int main() {

	int c;
	scanf("%d", &c);
	while (c--) {
		memset(cache, 0, sizeof(cache));
		int n, m;
		scanf("%d%d", &n, &m);
		m /= 100;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &price[i], &pref[i]);
			price[i] /= 100;
		}

		int best = 0;
		for (int i = 1; i <= m; i++) {
			int& ret = cache[i%MOD];
			for (int j = 0; j < n; j++) {
				if(i>=price[j])
				ret = max(ret, cache[(i - price[j])%MOD] + pref[j]);
			}
			best = max(best, ret);
		}
		printf("%d\n", best);
	}


}