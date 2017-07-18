#include <stdio.h>
#define MAX 999999999
#define min(a,b) (((a)<(b))?(a):(b))

int a[1000001];
int main(void) {
	int n, m;
	scanf("%d", &n);
	a[1] = 0; a[2] = 1; a[3] = 1;
	for (int i=4; i<=n; i++) {
		int k=MAX, l=MAX;
		m = a[i-1];
		if (i%2==0){
			k=a[(i/2)];m=min(m, k);
		}
		if (i%3==0) {
			l=a[(i/3)];m=min(m, l);
		}
		a[i] = m+1;
	}
	printf("%d", a[n]);
}