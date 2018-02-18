//BOJ
//ID : 2751 // merge sort
//2017/11/13

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[1000000], tmp[1000000];

void merge(int left, int mid, int right) {

	int i, j, k;
	i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
		tmp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];

	if (i > mid) memcpy(tmp + k, arr + j, sizeof(int)*(right - j + 1));
	else memcpy(tmp + k, arr + i, sizeof(int)*(mid - i + 1));

	memcpy(arr + left, tmp + left, sizeof(int)*(right - left + 1));
}

void msort(int left, int right) {

	int mid = (left + right) / 2;
	if (left < right) {
		msort(left, mid);
		msort(mid + 1, right);
		merge(left, mid, right);
	}

}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	msort(0, n - 1);
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
}