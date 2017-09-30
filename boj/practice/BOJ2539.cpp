//BOJ
//ID : 2539 // binary search
//2017/09/25

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m,k,f,a[1000],maxh=0;

bool check(int m) {

	int remain = k;

	for (int i = 0; i < f; i++) {

		if (i == f - 1) {
			remain--;
			break;
		}

		for (int j = i + 1; j < f; j++) {
			if (a[j] - a[i]  >= m) {
				remain--;
				i = j - 1;
				break;
			}
		}
	}
	return remain >= 0;
}


int main() {

	scanf("%d%d%d%d", &n, &m, &k,&f);

	for (int i = 0; i < f; i++) {
		int y, x;
		scanf("%d%d", &y, &x);
		maxh = max(maxh, y);
		a[i] = x;
	}

	sort(a, a + f);

	int lo = maxh - 1, hi = m + 1,mid;

	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) hi = mid;
		else lo = mid;
	}

	printf("%d", hi);
}