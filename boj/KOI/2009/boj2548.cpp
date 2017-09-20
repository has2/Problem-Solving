//BOJ
//ID : 2548
//2017/09/17

#include <cstdio>

int n, arr[20000],ret=20000,max=987654321;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int tmp = arr[i] - arr[j];
			sum += tmp < 0 ? -tmp : tmp;
		}
		if (max >= sum) {
			if (max == sum && ret < arr[i]) continue;

			max = sum;
			ret = arr[i];
		}
	}
	printf("%d", ret);
}