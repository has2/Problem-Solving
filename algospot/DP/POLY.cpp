#include <cstdio>
#include <cstring>
const int mod = 10000000;
int n,poly[101][101];

int polynum(int cur, int remain) {

	if (remain == 0) return 1;
	if (cur == 0) {
		int ret=0;
		for (int i = 1; i <= remain; i++) {
			ret += polynum(i, remain - i);
			ret %= mod;
		}
		return ret;
	}
	int& ret = poly[cur][remain];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 1; i <= remain; i++) {
		ret += ((cur+i-1)*polynum(i, remain - i))%mod;
		ret %= mod;
	}
	return ret;


}


int main(void) {
	int c;
	scanf("%d", &c);
	while (c--) {
		memset(poly, -1,sizeof(poly));
		scanf("%d", &n);
		printf("%d\n", polynum(0, n));
	}

}
