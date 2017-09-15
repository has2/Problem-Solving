//BOJ
//ID : 2790 / string
//2017/09/07

#include <cstdio>
#include <algorithm>
int n,a[300000],ret;
int main() {


	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);

	std::sort(a, a + n);

	int cnt = 0;
	int maxv = 0;
	int ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i < n - 1) {
			a[i + 1] += cnt;
			maxv = std::max(maxv, a[i + 1]);
		}
		if (a[i] + n >= maxv) ret++;
		cnt++;
	}
	printf("%d", ret);
}



