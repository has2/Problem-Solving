#include <cstdio>
int a[(1 << 25) / 32];
int main() {
	int v;
	while (scanf("%d", &v) != -1) {
		int p = v / 32;
		int q = 1 << (v % 32);
		if (a[p] & q) continue;
		a[p] += q;
		printf("%d ", v);
	}
}