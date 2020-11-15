#include <cstdio>
#include <algorithm>
using namespace std;
int N;
pair<int,int> a[500000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		a[i] = { k,i };
	}
	sort(a, a + N);
	int ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, a[i].second - i+1);
	printf("%d", ans);
}