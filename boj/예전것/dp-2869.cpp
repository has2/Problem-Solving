#include <stdio.h>
#include <cmath>

int main(void)
{
	long long A, B, V, d;
	scanf("%lld%lld%lld", &A, &B, &V);

	if (V==1||A==B) {
		printf("1");
		return 0;
	}
	d  =ceil((double)(V - A) / (A - B))+1;
	printf("%lld", d);
}