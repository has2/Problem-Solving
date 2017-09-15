//BOJ
//ID : 2467 / Binary Search
//2017/09/11

#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
int n, a[100000],ret=INT_MAX,a1,a2;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	if (a[0] >= 0 && a[n - 1] > 0) {
		printf("%d %d", a[0], a[1]);
		return 0;
	}
	if (a[0] < 0 && a[n - 1] <= 0) {
		printf("%d %d", a[n - 2], a[n - 1]);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int num = -a[i];
		int lo, hi;
		if (num > 0) {
			lo = i;
			hi = n;

			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (a[mid] <= num) lo = mid;
				else hi = mid;
			}
			if (hi < n && abs(a[i]+a[lo]) > abs(a[i]+a[hi])) {
				lo = hi;
			}
			if (ret > abs(a[i] + a[lo])) {
				ret = abs(a[i] + a[lo]);
				a1 = i; a2 = lo;
			}
		}
		else {
			lo = -1;
			hi = i-1;

			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (a[mid] >= num) hi = mid;
				else lo = mid;
			}
			if (lo > -1 && abs(a[i]+a[lo]) < abs(a[i]+a[hi])) {
				hi = lo;
			}
			if (ret > abs(a[i] + a[hi])) {
				ret = abs(a[i] + a[hi]);
				a1 = hi; a2 = i;
			}
		}
	}
	printf("%d %d", a[a1], a[a2]);
}