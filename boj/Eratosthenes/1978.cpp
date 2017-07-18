#include <cstdio>
#include <cstring>
bool isPrime[1001];

int main() {
	
	memset(isPrime, 1, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i*i <= 1000; i++) {
		if (isPrime[i]) {
			for (int j = i*i; j <= 1000; j += i)
				isPrime[j] = false;
		}
	}

	int n,ret=0;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		if (isPrime[num]) ret++;
	}
	printf("%d\n", ret);
}