#include <cstdio>

using namespace std;

long long segtree[4000001];
long long d[1000001];

long long maketree(int L, int R, int cur_node) {

	int mid = (L + R) / 2;

	return segtree[cur_node] = (L == R) ? d[L] : (maketree(L, mid, cur_node * 2) + maketree(mid + 1, R, cur_node * 2 + 1));

}

long long sum(int L, int R, int cur_node, int cur_L, int cur_R) {
	
	if (L > cur_R || R < cur_L) return 0;
	if (L <= cur_L && cur_R <= R) return segtree[cur_node];
	int mid = (cur_L + cur_R) / 2;
	return sum(L, R, cur_node * 2, cur_L, mid) + sum(L, R, cur_node * 2 + 1, mid + 1, cur_R);
	
}

void Modify(int i, long long value,int size) {
	
	i = size + i - 1;
	segtree[i] = value;
	for(i /= 2; i > 0 ; i/=2)
		segtree[i] = segtree[i * 2] + segtree[i * 2 + 1];

}

int main(void)
{
	int N, M,size,q,a,b;
	scanf("%d%d", &N, &M);
	for (size = 1; size < N; size *= 2) {}

	maketree(1, size, 1);

	while (M--) {
		scanf("%d%d%d", &q, &a, &b);
		if (q == 0) {
			if (a < b)
				printf("%d\n", sum(a, b, 1, 1, size));
			else
				printf("%d\n", sum(b, a, 1, 1, size));
		}
		else
			Modify(a, b, size);
	}

	return 0;
}