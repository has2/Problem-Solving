//BOJ
//ID : 2467 / Binary Search
//2017/09/17

#include <cstdio>

int ret,n,k,seq[100000];
int main() {
	scanf("%d%d", &n, &k);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
		if (i < k) sum += seq[i];
	}
	ret = sum;
	int tail = 0;
	for (int i = k; i < n; i++) {
		sum += seq[i]-seq[tail++];
		ret = ret < sum ? sum : ret;
	}
	printf("%d", ret);
}