//BOJ
//ID : 2437 / Greedy
//2017/09/17

#include <cstdio>
#include <algorithm>

int n, arr[1000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	std::sort(arr, arr + n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 < arr[i]) break;
		sum += arr[i];
	}
	printf("%d", sum + 1);
}