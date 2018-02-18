//BOJ
//ID : 2751 // quick sort
//2017/11/13

#include <stdio.h>
int arr[1000002],n;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int left, int right) {

	int pivot = arr[right];
	int i = left-1;
	int j = right;

	while (1) {

		while (i < right && arr[++i] <= pivot);
		while (arr[--j] > pivot);

		if (i < j) {
			swap(&arr[i], &arr[j]);
		}
		else {
			swap(&arr[i], &arr[right]);
			return i;
		}
	}
}

void qsort(int left, int right) {

	int pidx = partition(left, right);
	if (left < right) {
		qsort(left, pidx-1);
		qsort(pidx + 1, right);
	}

}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	qsort(1, n);
	for (int i = 1; i <= n; i++) printf("%d\n", arr[i]);
}