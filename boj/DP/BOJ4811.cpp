//BOJ
//ID : 4811 // dp
//2017/09/27

#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int n;
ll cache[31][31];

ll sol(int full, int half) {

	if (full==0 && half ==0) return 1;

	ll& ret = cache[full][half];
	if (ret != -1) return ret;

	ret = 0;

	if(full>0) ret += sol(full - 1, half + 1);
	if (half > 0) ret += sol(full, half - 1);

	return ret;
}

int main() {

	while (scanf("%d",&n)!=EOF) {
		memset(cache, -1, sizeof(cache));
		if (n == 0) return 0;
		printf("%lld\n", sol(n - 1, 1));
	}
}