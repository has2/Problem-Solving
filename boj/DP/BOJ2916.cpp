//BOJ
//ID : 2916 // dp
//2017/10/01
#include <cstdio>
#include <cmath>
using namespace std;

int n, k,tmp;
bool a[360];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		a[tmp] = 1;
	}
	a[0] = 1;
	while (1) {

		bool flag = 0;

		for (int i = 1; i < 360; i++) {

			if (!a[i]) continue;

			for (int j = 1; j < 360; j++) {
				if (!a[j]) continue;
				int absv = abs(i - j);
				if (0 < absv && absv < 360 && !a[absv]) {
					a[absv] = 1;
					flag = 1;
				}
			}
		}

		for (int i = 1; i < 360; i++) {

			if (!a[i]) continue;

			for (int j = 1; j < 360; j++) {
				if (!a[j]) continue;
				int absv = (i + j)%360;
				if (0 < absv && absv < 360 && !a[absv]) {
					a[absv] = 1;
					flag = 1;
				}
			}
		}
		if (flag == 0) break;
	}
	while (k--) {
		scanf("%d", &tmp);
		if (a[tmp]) puts("YES");
		else puts("NO");
	}
}