#include <cstdio>
long long N, d[1000001],m=1e9;
int main() {
	scanf("%lld", &N);
	d[2] = 1;
	for (int i = 3; i <= N; i++) d[i] = ((i - 1)*(d[i - 1] + d[i - 2]))%m;
	printf("%lld", d[N]);
}