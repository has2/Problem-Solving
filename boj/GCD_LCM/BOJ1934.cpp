#include <cstdio>
#define SWAP(a,b,tmp) {tmp = a; a = b; b = tmp;}  

int lcm(int a, int b) {
	int mod = a % b;
	int multi = a * b;
	
	while (mod != 0) {
		a = b;
		b = mod;
		mod = a % b;
	}

	return multi / b;
}

int main(void) {
	int T,a,b,tmp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		if (a < b) SWAP(a, b, tmp);
		printf("%d\n", lcm(a, b));
	}
}