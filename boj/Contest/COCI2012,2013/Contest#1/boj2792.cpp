//BOJ
//ID : 2792 / binary search
//2017/09/07

#include <cstdio>
#include <algorithm>
int n,m,a[300000];

bool check(int k) {

	int cnt = 0;
	for (int i = 0; i < m; i++) 
		cnt += a[i] / k + (a[i]%k > 0 ? 1 : 0);
	
	return cnt <= n;
}

int main() {
	scanf("%d%d", &n, &m);

	int maxv = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		maxv = std::max(maxv, a[i]);
	}

	int lo = 0, hi = maxv + 1,mid;

	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) hi = mid;
		else lo = mid;
	}
	printf("%d", hi);
}



