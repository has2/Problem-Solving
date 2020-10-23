#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N, a[100000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);

	std::vector<int> dp(1,a[0]);

	for (int i = 1; i < N; i++) {
		if (dp.back() < a[i]) dp.push_back(a[i]);
		else {
			auto it = lower_bound(dp.begin(), dp.end(), a[i]);
			*it = a[i];
		}
	}
	printf("%d", N - dp.size());
}