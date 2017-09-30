//BOJ
//ID : 10815 // binary search
//2017/09/24

#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[500000];
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int m,num;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &num);

		int lo=-1, hi=n, mid;

		while (lo + 1 < hi) {

			mid = (lo + hi) / 2;

			if (a[mid] >= num) hi = mid;
			else lo = mid;
		}

		if (hi <= n && a[hi] == num) printf("1 ");
		else printf("0 ");
	}
}
