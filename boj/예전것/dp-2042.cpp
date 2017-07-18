#include <cstdio>


long long tree[4000001];
long long value[1000001];
int sequence[1000001];
int idx_value = 1;

long long maketree(int idx, int left, int right)
{
	if (left == right) {
		sequence[idx_value++] = idx;
		tree[idx] = value[left];
	}
	else
		tree[idx] = maketree(2 * idx, left, (left + right) / 2)+maketree(2 * idx + 1, (left + right) / 2 + 1, right);

	return tree[idx];
}

void changetree(int target,long long update)
{
	int temp_idx = sequence[target];
	long long old = value[target];
	value[target] = update;
	while (temp_idx != 0)
	{
		tree[temp_idx] = tree[temp_idx] - old + value[target];
		temp_idx /= 2;
	}
}

long long sum(int node,int c_left,int c_right,int left, int right)
{
	if (c_left<left || c_right>right) {
		if (c_left<left&&c_right<left || c_left>right&&c_right>right)
			return 0;
		return sum(node * 2, c_left, (c_left + c_right) / 2, left, right) + sum(node * 2 + 1, (c_left + c_right) / 2 + 1, c_right, left, right);
	}
	else if (c_left >= left&&c_right <= right) {
		return tree[node];
	}
}



int main(void)
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &value[i]);
	maketree(1, 1, N);
	for (int i = 1; i <= M + K; i++) {
		int a, b; long long c;
		scanf("%d%d%lld", &a, &b, &c);
		if (a == 1)
			changetree(b, c);
		else
			printf("%lld\n",sum(1, 1,N, b, c));
	}

	//long long a = sum(1, 1,5, 1, 4);
	//printf("%lld", a);
	//changetree(3, 6);
	//for (int i = 1; i <= 9; i++)
	//	printf("%lld,", tree[i]);
	//printf("%lld", sum(1, 2, 5, 1, 5));

}