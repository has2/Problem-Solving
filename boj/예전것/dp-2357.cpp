#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 9999999999
#define MIN -1

long long tree_min[400001];
long long value_min[100001];
long long tree_max[400001];
long long value_max[100001];

long long makemintree(int idx, int left, int right)
{
	if (left == right) {
		tree_min[idx] = value_min[left];
	}
	else
		tree_min[idx] = min(makemintree(2 * idx, left, (left + right) / 2), makemintree(2 * idx + 1, (left + right) / 2 + 1, right));

	return tree_min[idx];
}

long long makemaxtree(int idx, int left, int right)
{
	if (left == right) {
		tree_max[idx] = value_max[left];
	}
	else
		tree_max[idx] = max(makemaxtree(2 * idx, left, (left + right) / 2), makemaxtree(2 * idx + 1, (left + right) / 2 + 1, right));

	return tree_max[idx];
}

long long minvalue(int node, int c_left, int c_right, int left, int right)
{
	if (c_left > right || c_right < left) return MAX;
	if (c_left >= left&&c_right <= right) return tree_min[node];
	return min(minvalue(node * 2, c_left, (c_left + c_right) / 2, left, right), minvalue(node * 2 + 1, (c_left + c_right) / 2 + 1, c_right, left, right));
}

long long maxvalue(int node, int c_left, int c_right, int left, int right)
{
	if (c_left > right || c_right < left) return MIN;
	if (c_left >= left&&c_right <= right) return tree_max[node];
	return max(maxvalue(node * 2, c_left, (c_left + c_right) / 2, left, right), maxvalue(node * 2 + 1, (c_left + c_right) / 2 + 1, c_right, left, right));
}

int main(void)
{
	int N, M;
	
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) {
			long long a;
			scanf("%lld", &a);
			value_min[i] = a; value_max[i] = a;
		}
		makemintree(1, 1, N);
		makemaxtree(1, 1, N);
		for (int i = 0; i < M; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%lld %lld\n", minvalue(1, 1, N, a, b), maxvalue(1, 1, N, a, b));
		}
}
