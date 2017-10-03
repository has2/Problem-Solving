//BOJ
//ID : 3020 // sort
//2017/09/30
#include <cstdio>
#include <algorithm>
using namespace std;

int n, h, u[100001], d[100001], c[500001];

int main() {

	scanf("%d%d", &n, &h);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		if (i % 2) u[i / 2 + 1] = k;
		else d[i / 2] = k;
	}

	sort(u+1, u + n / 2 + 1);
	sort(d+1, d + n / 2 + 1);

	for (int i = 1; i <= u[1]; i++)
		c[i] = n / 2;

	for (int i = 2; i <= n / 2; i++) {
		if (u[i - 1] == u[i]) continue;

		for (int j = u[i - 1] + 1; j <= u[i]; j++)
			c[j] = n / 2 - (i-1);
	}

	for (int i = 1; i <= d[1]; i++)
		c[h+1-i] += n / 2;

	for (int i = 2; i <= n / 2; i++) {
		if (d[i - 1] == d[i]) continue;
		for (int j = d[i - 1] + 1; j <= d[i]; j++)
			c[h+1-j] += n / 2 - (i-1);
	}

	sort(c+1, c + 1 + h);
	int cnt = 1;

	for (int i = 2; i <= h; i++) {
		if (c[i - 1] != c[i]) break;
		cnt++;
	}
	printf("%d %d", c[1], cnt);
}