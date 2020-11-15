#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int mxN = 1e5 + 1;
int N, a[mxN];
int main() {
	while (1) {
		if (scanf("%d", &N) == EOF) return 0;
		
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);
		vector<int> dp;
		for (int i = 0; i < N; i++) {
			if (dp.empty() || dp.back() < a[i]) {
				dp.push_back(a[i]);
			}
			else {
				auto it = lower_bound(dp.begin(), dp.end(), a[i]);
				*it = a[i];
			}
		}
		printf("%d\n", dp.size());
		getchar();
	}
}