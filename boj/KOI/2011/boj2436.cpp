//BOJ
//ID : 2436 / gcd/lcm lcm = gcd*x*y에서 x,y는 서로수
//2017/09/17

#include <cstdio>
#include <cmath>
int A, B, xy;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	scanf("%d%d", &A, &B);
	xy = B / A;

	int max = 1;
	for (int i = 1; i <= sqrt(xy); i++) {
		if (xy%i == 0 && gcd(i, xy / i) == 1) {
			max = i;
		}
	}
	printf("%d %d", max*A, (xy / max)*A);
}