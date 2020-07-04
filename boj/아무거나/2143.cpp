#include <cstdio>
#include <map>

using namespace std;
int t, n, m, A[1000], B[1000];
long long ret;
int main() {

	scanf("%d%d", &t,&n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &B[i]);
	map<long long, long long> aMap;

	for (int i = 0; i < n; i++) {
		long long sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			aMap[sum]++;
		}
	}

	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = i; j < m; j++) {
			sum += B[j];
			ret += aMap[t - sum];
		}
	}

	printf("%lld", ret);
}