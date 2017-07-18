#include <cstdio>

long long L[10000];
long long ans=1;

int get(long long lan[], int len,int k) {
	int cnt=0;
	for (int i = 0; i < k; i++)
		cnt += lan[i] / len;

	return cnt;
}

long long search(long long l, long long r, long long lan[], int target, int K)
{
	if (l > r) {
		return ans;
	}

	long long mid = (l + r) / 2;

	int num = get(lan, mid, K);

	if (num >= target) {
		ans = mid;
		return search(mid + 1, r, lan, target, K);
	}
	else if (num < target) {
		return search(l, mid - 1, lan, target, K);
	}
}

int main(void)
{
	int K, N;
	long long max = 0;
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		long long a; scanf("%lld", &a);
		if (max < a) max = a;
		L[i] = a;
	}
	
	printf("%lld",search(1, max, L, N, K));
}