#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
	int N, S;
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);

	int ans = 987654321;
	int sum = 0, l = 0;
	for (int i = 0; i < N; i++) {
		sum += a[i];
		if (sum >= S) {
			while (sum >= S) sum -= a[l++];
			sum += a[--l];
			ans = min(i - l +1, ans);
		}
	}
	printf("%d", ans == 987654321 ? 0 : ans);
}