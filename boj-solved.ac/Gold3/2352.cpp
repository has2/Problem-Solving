#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, a[40001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	
	vector<int> dp(1,0);
	for (int i = 1; i <= N; i++) {
		if (a[i] > dp.back()) dp.push_back(a[i]);
		else {
			auto it = lower_bound(dp.begin(), dp.end(), a[i]);
			*it = a[i];
		}
	}
	printf("%d", dp.size()-1);
}