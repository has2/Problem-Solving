#include <cstdio>
const int MAX = 10000000;
int minfac[MAX+1];

int main() {

	for (int i = 2; i <= MAX; i++)
		minfac[i] = i;

	for (int i = 2; i*i <= MAX; i++) 
		if (minfac[i] == i) 
			for (int j = i*i; j <= MAX; j += i) 
				if (minfac[j] == j)
					minfac[j] = i;
	
	int c;
	scanf("%d", &c);
	while (c--) {
		int n, lo, hi,ret=0;
		scanf("%d%d%d", &n, &lo, &hi);
		for (int i = lo; i <= hi; i++) {

			int k = i;
			int prev ,cur = minfac[k];
			int cnt = 0,total = 1;
			while (cur>0) {
				k /= cur;
				cnt++;
				prev = cur;
				cur = minfac[k];

				if (prev != cur) {
					total *= (cnt + 1);
					cnt = 0;
				}
			}
			total *= (cnt + 1);

			if (total == n) ++ret;
		}
		printf("%d\n", ret);
	}
		
	



}