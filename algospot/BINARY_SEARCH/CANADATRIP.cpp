#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int L[5000], M[5000], G[5000];
int N, K;

bool decision(int x) {
	
	int total = 0;
	for (int i = 0; i < N; i++) {
		if (L[i] - M[i] > x) continue;

		total += (min(x, L[i]) - (L[i] - M[i])) / G[i] + 1;

	}

	return total >= K;
}

int main() {

	int c;
	scanf("%d", &c);
	while (c--) {

		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) 
			scanf("%d%d%d", &L[i], &M[i], &G[i]);
		
		int lo = -1, hi = 8030001;

		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;

			if (decision(mid)) hi = mid;
			else lo = mid;
		}

		printf("%d\n", hi);
	}

}