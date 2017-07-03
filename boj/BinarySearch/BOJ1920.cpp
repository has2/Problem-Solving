#include <cstdio>
#include <algorithm>

int arr[100000];

int main(void) {

	int N, M, num, ans, l, r;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	std::sort(arr, arr + N);

	scanf("%d", &M);
	while (M--) {
		scanf("%d", &num);

		l = 0; r = N - 1; ans = 0;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (arr[mid] > num) r = mid - 1;
			else if (arr[mid] < num) l = mid + 1;
			else {
				ans = 1;
				break;
			}
		}
		printf("%d\n", ans);
	}


}