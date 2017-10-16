//BOJ
//ID : 13458 // greedy
//2017/10/16

#include <cstdio>

typedef long long ll;

int n;
int a[1000000], b, c;
ll total;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d%d", &b, &c);

	for(int i=0;i<n;i++){
		int r=a[i];
		total++;
		if (b - r >= 0) continue;
		else {
			total += (r - b) / c;
			if ((r - b) % c != 0) total++;
		}
	}
	printf("%d", total);
}