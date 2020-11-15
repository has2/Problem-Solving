#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int mxN = 1e6 + 1;
int N, a[101],np[mxN],cnt[mxN];
int getCnt(int a, int i) {
	int c = 0;
	while (a%i == 0) {
		a /= i;
		c++;
	}
	return c;
}
void update(int a) {
	for (int i = 2; i <= mxN; i++) {
		if (!np[i] && a%i == 0) cnt[i] += getCnt(a,i);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);

	np[1] = 1;
	for (int i = 2; i <= mxN; i++) {
		if (np[i]) continue;
		for (int j = 2*i; j <= mxN; j += i) np[j] = 1;
	}
	for (int i = 0; i < N; i++) update(a[i]);

	int ans = 1;
	int move = 0;
	for (int i = 2; i <= mxN; i++) {
		if (cnt[i] > 0) {
			int avg = cnt[i] / N;
			if (avg == 0) continue;
			ans *= pow(i,avg);
			int r = cnt[i] % N;
			for (int j = 0; j < N; j++) {
				int c = getCnt(a[j], i);
				if (avg > c) move += avg - c;
			}
		}
	}
	printf("%d %d\n",ans, move);
}