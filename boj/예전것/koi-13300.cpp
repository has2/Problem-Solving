#include <cstdio>
#include <cmath>

int st[2][7];
int main(void)
{
	int N, K; scanf("%d%d", &N, &K);
	int a, b;
	int sum=0;
	while (N--)
	{
		scanf("%d%d", &a, &b);
		st[a][b]++;
	}

	for (int i = 0; i < 2; i++) 
		for (int j = 1; j < 7; j++) 
			sum += (int)ceil((float)st[i][j] / K);
		
	printf("%d", sum);
}