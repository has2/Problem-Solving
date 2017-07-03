#include <cstdio>
#include <algorithm>
using namespace std;

int A[4000], B[4000],C[4000],D[4000];
int AB[16000000], CD[16000000];

int main(void) {
	
	int N, idx = 0;
	long long ret = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			AB[idx] = A[i] + B[j];
			CD[idx++] = C[i] + D[j];
		}

	sort(AB, AB + idx);

	for (int i = 0; i < N*N; i++) {

		int lo, hi, mid,sum;
		lo = -1; hi = idx;
		while (lo + 1 < hi) {
			mid = (lo + hi) / 2;
			sum = AB[mid] + CD[i];
			if (sum >= 0) hi = mid;
			else lo = mid;
		}
		int start;
		if (AB[hi] + CD[i] != 0) continue;
		else start = hi;

		lo = -1; hi = idx;
		while (lo + 1 < hi) {
			mid = (lo + hi) / 2;
			sum = AB[mid] + CD[i];
			if (sum > 0) hi = mid;
			else lo = mid;
		}
		
		ret += hi - start;
	}
	printf("%lld\n", ret);
}