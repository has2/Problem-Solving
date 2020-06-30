#include <cstdio>

int k,n,m,A[1000], B[1000],Acnt[2000001], Bcnt[2000001],ret;

void func(int p, int arr[], int arrCnt[]) {
	for (int i = 1; i <= p; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) sum += arr[j];
		arrCnt[sum]++;
		if (sum == k) ret++;
		
		if (i == p) break;
		for (int j = 1; j < p; j++) {
			sum -= arr[j - 1];
			sum += arr[(j + i - 1) % p];
			arrCnt[sum]++;
			if (sum == k) ret++;
		}
	}
}

int main() {
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 0; i < m; i++) scanf("%d", &B[i]);

	func(n, A, Acnt);
	func(m, B, Bcnt);

	for (int i = 1; i < k; i++) {
		int j = k - i;
		ret += Acnt[i] * Bcnt[j];
	}
	printf("%d", ret);
}